#include "GeneticAlgorithm.h"
#include "MapInfo.h"
/* private */

// 교차 함수
void Genetic::CrossOver( const std::vector<int>& _mam,
						 const std::vector<int>& _dad,
						 std::vector<int>&		 _baby1,
						 std::vector<int>&		 _baby2 )
{
	// 교차율보다 교차하지않을 확률이 클 경우, 부모 염색체가 서로 같을때
	if (((rand() % (RAND_MAX + 1)) > dCrossoverRate) || _mam == _dad)
	{
		// 유전자 정보를 그대로 물려받는다.
		_baby1 = _mam;
		_baby2 = _dad;
		return;
	}

	// 유전자를 교차할 지점을 랜덤으로 받는다.
	int iCrossPoint = rand() % iChromoLenght;

	// 처음부터 교차지점 전까지 유전자정보 각 각 저장
	for (int i = 0; i < iCrossPoint; ++i)
	{
		_baby1.push_back(_mam[i]);
		_baby2.push_back(_dad[i]);
	}

	// 교차지점 후 부터 마지막 까지 유전자 정보 각 각 대입
	for (int i = iCrossPoint; i < iChromoLenght; ++i)
	{
		_baby1.push_back(_dad[i]);
		_baby2.push_back(_mam[i]);
	}
}

void Genetic::Mutate(std::vector<int>& vecBits)
{
	// 염색체의 비트 하나하나 돌연변이 확률을 적용
	for (unsigned int i = 0; i < vecBits.size(); ++i)
	{
		if (rand() % (RAND_MAX + 1) < dMutationRate) // 돌연변이확률에 걸릴경우
			vecBits[i] = !vecBits[i]; // NOT 연산자로 비트반전
	}
}

// 게놈집단의 적응도 갱신 및 가장 높은 적응도를 가진 게놈 검색
void Genetic::UpdateFitnessScores()
{
	iFittestGenome			= 0;  // 가장 높은 적응도의 인덱스
	dBestFitnessScore		= 0;  // 가장 높은 적응도
	dTotalFitnessScore		= 0;  // 적응도의 총합

	// 게놈집단의 염색체 개수 만큼 반복
	for (int i = 0; i < iPopSize; ++i)
	{
		// 염색체의 유전자정보를 해석한 값 저장
		std::vector<int> vecDirections = Decode(vecGenomes[i].vecBits);
		
		// 염색체의 적응도를 계산하여 저장한다.
		vecGenomes[i].SetFitness(TestRoute(vecDirections));

		// 룰렛 선택을 위한 적응도 총합 계산
		dTotalFitnessScore += vecGenomes[i].GetFitness();

		// 염색체가 가장 높은 적응도 보다 높을 경우
		if (vecGenomes[i].GetFitness() > dBestFitnessScore)
		{
			dBestFitnessScore = vecGenomes[i].GetFitness(); // 가장 높은 적응도로 설정

			iFittestGenome = i; // 적응도가 가장 높은 염색체 인덱스값 저장

			// 적응도가 1인 유전자일 경우!!
			if (vecGenomes[i].GetFitness() == 1)
			{
			    bCheckFitness = false;
				break;
			}
		}
		Print(i);
	}
	//cout << "세대 : " << iGenteration << endl;
	//Print();
}

// 염색체의 유전자 정보 해석
std::vector<int> Genetic::Decode(const std::vector<int>& bit)
{
	std::vector<int> Directions; // 해석한 유전자 정보(방향값)이 들어있는 변수
	for (unsigned int i = 0; i < bit.size(); i += iGeneLength) // 유전자 당 2비트를 차지한다.
	{
		std::vector<int> tempGene; // 해석한 유전자를 임시로 담는 변수

		for (int j = 0; j < iGeneLength; ++j)
		{
			tempGene.push_back(bit[i + j]); // 임시 유전자에 유전자값 저장
		}

		Directions.push_back(BinToInt(tempGene)); // 유전자를 10진수로 해석 후 방향값이 저장되는 벡터에 저장
		
	}

	return Directions;
}

// 비트들의 벡터요소를 십진수로 변환
int Genetic::BinToInt(const std::vector<int>& v)
{
	int iValue = 0; // 십진수로 변환한 값 저장
	int iMulti = 1; // 이진수 자리수에 대해 알맞은 연산을 하기 위한 변수
	for (int i = iGeneLength; i > 0; i--) // 이진수의 첫째자리부터 계산을 위해 시작값을 iGeneLen으로 설정
	{
		iValue += v[i - 1] * iMulti;
		iMulti *= 2;
	}
	return iValue;
}


// 초기 게놈집단 초기화
void Genetic::CreateStartPopulation()
{
	// 게놈 집단 벡터 초기화
	vecGenomes.clear();

	for (int i = 0; i < iPopSize; i++)
	{
		vecGenomes.push_back(Genome(iChromoLenght)); // 염색체당 비트수를 인자로 준다.
	}
	
	dBestFitnessScore = 0;
	dTotalFitnessScore = 0;
	iFittestGenome = 0;
	iGenteration = 0;
}

Genome& Genetic::Roulette()
{
	// 0 ~ 적응도 총합까지 난수 생성
	double dRulette = (rand() / (RAND_MAX + 1.0)) * dTotalFitnessScore;

	// 게놈들의 적응도 누적 합계
	double dTotal = 0.0;  

	// 선택된 게놈 인덱스
	int iSelectGenome = 0;

	for (int i = 0; i < iPopSize; ++i)
	{
		// 게놈들의 적응도 누적
		dTotal += vecGenomes[i].GetFitness();

		if (dTotal > dRulette)
		{
			iSelectGenome = i;
			break;
		}
	}
	return vecGenomes[iSelectGenome]; // 선택된 게놈 반환
}

/* public */

// 생성자
Genetic::Genetic(double _CrossRate, double _MutRate, int _PopSize, int _NumBit, int _GenLen)
	:	dCrossoverRate(_CrossRate), dMutationRate(_MutRate), iPopSize(_PopSize), iChromoLenght(_NumBit),
		iGenteration(0), iGeneLength(_GenLen)
{
	CreateStartPopulation(); // 초기 게놈집단 초기화

	bCheckFitness = true;
}

// 시대
void Genetic::Epoch()
{
	// 게놈집단의 적응도 갱신, 가장 높은 적응도 개체 검색
	UpdateFitnessScores(); 

	// 새로운 게놈집단 수
	int iNewBabies = 0;

	// 새로운 게놈들을 임시저장할 변수
	std::vector<Genome> vecBabyGenome;

	while (iNewBabies < iPopSize)
	{
		// 부모 염색체 2개 선택
		Genome mom = Roulette();
		Genome dad = Roulette();

		// 부모 염색체 교차 및 자식 염색체에 대입
		Genome baby1, baby2; // 자식 염색체
		
		// 부모 염색체들의 유전자정보를 인자로 넣겨 교차시킨다.
		CrossOver(mom.vecBits, dad.vecBits, baby1.vecBits, baby2.vecBits);

		// 돌연변이 확률 적용!
		Mutate(baby1.vecBits);
		Mutate(baby2.vecBits);

		// 임시 게놈집단에 자식 게놈을 넣는다.
		vecBabyGenome.push_back(baby1);
		vecBabyGenome.push_back(baby2);

		iNewBabies += 2; // 새로 생성한 자식 게놈 갯수 증가
	}

	// 한 세대를 거친 후 이며
	// 부모 게놈 집단을 새로운 자식 게놈집단으로 바꿔준다.
	vecGenomes = vecBabyGenome;

	// 세대 증가
	++iGenteration;
}

int Genetic::GetGeneration() const
{
	return iGenteration;
}

void Genetic::Print(int i)
{
	{
		PrintMap(); // 임시.
		CopyMap();
		cout << "첫번째 염색체 : " << i + 1 << endl;
		cout << "세대 : " << iGenteration << endl;
		cout << "가장 높은 적응도 : " << dBestFitnessScore << endl;
		cout << "가장 적응도 높은 유전자 : ";
		for (int j = 0; j < vecGenomes[iFittestGenome].vecBits.size(); ++j)
			cout << vecGenomes[iFittestGenome].vecBits[j];
		cout << endl;
	//	system("pause");
		system("cls");
	}
}

void Genetic::Print()
{
	{
		PrintMap(); // 임시.
		CopyMap();
		cout << "세대 : " << iGenteration << endl;
		system("pause");
		system("cls");
	}
}