#include "GeneticAlgorithm.h"
#include "MapInfo.h"
/* private */

// ���� �Լ�
void Genetic::CrossOver( const std::vector<int>& _mam,
						 const std::vector<int>& _dad,
						 std::vector<int>&		 _baby1,
						 std::vector<int>&		 _baby2 )
{
	// ���������� ������������ Ȯ���� Ŭ ���, �θ� ����ü�� ���� ������
	if (((rand() % (RAND_MAX + 1)) > dCrossoverRate) || _mam == _dad)
	{
		// ������ ������ �״�� �����޴´�.
		_baby1 = _mam;
		_baby2 = _dad;
		return;
	}

	// �����ڸ� ������ ������ �������� �޴´�.
	int iCrossPoint = rand() % iChromoLenght;

	// ó������ �������� ������ ���������� �� �� ����
	for (int i = 0; i < iCrossPoint; ++i)
	{
		_baby1.push_back(_mam[i]);
		_baby2.push_back(_dad[i]);
	}

	// �������� �� ���� ������ ���� ������ ���� �� �� ����
	for (int i = iCrossPoint; i < iChromoLenght; ++i)
	{
		_baby1.push_back(_dad[i]);
		_baby2.push_back(_mam[i]);
	}
}

void Genetic::Mutate(std::vector<int>& vecBits)
{
	// ����ü�� ��Ʈ �ϳ��ϳ� �������� Ȯ���� ����
	for (unsigned int i = 0; i < vecBits.size(); ++i)
	{
		if (rand() % (RAND_MAX + 1) < dMutationRate) // ��������Ȯ���� �ɸ����
			vecBits[i] = !vecBits[i]; // NOT �����ڷ� ��Ʈ����
	}
}

// �Գ������� ������ ���� �� ���� ���� �������� ���� �Գ� �˻�
void Genetic::UpdateFitnessScores()
{
	iFittestGenome			= 0;  // ���� ���� �������� �ε���
	dBestFitnessScore		= 0;  // ���� ���� ������
	dTotalFitnessScore		= 0;  // �������� ����

	// �Գ������� ����ü ���� ��ŭ �ݺ�
	for (int i = 0; i < iPopSize; ++i)
	{
		// ����ü�� ������������ �ؼ��� �� ����
		std::vector<int> vecDirections = Decode(vecGenomes[i].vecBits);
		
		// ����ü�� �������� ����Ͽ� �����Ѵ�.
		vecGenomes[i].SetFitness(TestRoute(vecDirections));

		// �귿 ������ ���� ������ ���� ���
		dTotalFitnessScore += vecGenomes[i].GetFitness();

		// ����ü�� ���� ���� ������ ���� ���� ���
		if (vecGenomes[i].GetFitness() > dBestFitnessScore)
		{
			dBestFitnessScore = vecGenomes[i].GetFitness(); // ���� ���� �������� ����

			iFittestGenome = i; // �������� ���� ���� ����ü �ε����� ����

			// �������� 1�� �������� ���!!
			if (vecGenomes[i].GetFitness() == 1)
			{
			    bCheckFitness = false;
				break;
			}
		}
		Print(i);
	}
	//cout << "���� : " << iGenteration << endl;
	//Print();
}

// ����ü�� ������ ���� �ؼ�
std::vector<int> Genetic::Decode(const std::vector<int>& bit)
{
	std::vector<int> Directions; // �ؼ��� ������ ����(���Ⱚ)�� ����ִ� ����
	for (unsigned int i = 0; i < bit.size(); i += iGeneLength) // ������ �� 2��Ʈ�� �����Ѵ�.
	{
		std::vector<int> tempGene; // �ؼ��� �����ڸ� �ӽ÷� ��� ����

		for (int j = 0; j < iGeneLength; ++j)
		{
			tempGene.push_back(bit[i + j]); // �ӽ� �����ڿ� �����ڰ� ����
		}

		Directions.push_back(BinToInt(tempGene)); // �����ڸ� 10������ �ؼ� �� ���Ⱚ�� ����Ǵ� ���Ϳ� ����
		
	}

	return Directions;
}

// ��Ʈ���� ���Ϳ�Ҹ� �������� ��ȯ
int Genetic::BinToInt(const std::vector<int>& v)
{
	int iValue = 0; // �������� ��ȯ�� �� ����
	int iMulti = 1; // ������ �ڸ����� ���� �˸��� ������ �ϱ� ���� ����
	for (int i = iGeneLength; i > 0; i--) // �������� ù°�ڸ����� ����� ���� ���۰��� iGeneLen���� ����
	{
		iValue += v[i - 1] * iMulti;
		iMulti *= 2;
	}
	return iValue;
}


// �ʱ� �Գ����� �ʱ�ȭ
void Genetic::CreateStartPopulation()
{
	// �Գ� ���� ���� �ʱ�ȭ
	vecGenomes.clear();

	for (int i = 0; i < iPopSize; i++)
	{
		vecGenomes.push_back(Genome(iChromoLenght)); // ����ü�� ��Ʈ���� ���ڷ� �ش�.
	}
	
	dBestFitnessScore = 0;
	dTotalFitnessScore = 0;
	iFittestGenome = 0;
	iGenteration = 0;
}

Genome& Genetic::Roulette()
{
	// 0 ~ ������ ���ձ��� ���� ����
	double dRulette = (rand() / (RAND_MAX + 1.0)) * dTotalFitnessScore;

	// �Գ���� ������ ���� �հ�
	double dTotal = 0.0;  

	// ���õ� �Գ� �ε���
	int iSelectGenome = 0;

	for (int i = 0; i < iPopSize; ++i)
	{
		// �Գ���� ������ ����
		dTotal += vecGenomes[i].GetFitness();

		if (dTotal > dRulette)
		{
			iSelectGenome = i;
			break;
		}
	}
	return vecGenomes[iSelectGenome]; // ���õ� �Գ� ��ȯ
}

/* public */

// ������
Genetic::Genetic(double _CrossRate, double _MutRate, int _PopSize, int _NumBit, int _GenLen)
	:	dCrossoverRate(_CrossRate), dMutationRate(_MutRate), iPopSize(_PopSize), iChromoLenght(_NumBit),
		iGenteration(0), iGeneLength(_GenLen)
{
	CreateStartPopulation(); // �ʱ� �Գ����� �ʱ�ȭ

	bCheckFitness = true;
}

// �ô�
void Genetic::Epoch()
{
	// �Գ������� ������ ����, ���� ���� ������ ��ü �˻�
	UpdateFitnessScores(); 

	// ���ο� �Գ����� ��
	int iNewBabies = 0;

	// ���ο� �Գ���� �ӽ������� ����
	std::vector<Genome> vecBabyGenome;

	while (iNewBabies < iPopSize)
	{
		// �θ� ����ü 2�� ����
		Genome mom = Roulette();
		Genome dad = Roulette();

		// �θ� ����ü ���� �� �ڽ� ����ü�� ����
		Genome baby1, baby2; // �ڽ� ����ü
		
		// �θ� ����ü���� ������������ ���ڷ� �ְ� ������Ų��.
		CrossOver(mom.vecBits, dad.vecBits, baby1.vecBits, baby2.vecBits);

		// �������� Ȯ�� ����!
		Mutate(baby1.vecBits);
		Mutate(baby2.vecBits);

		// �ӽ� �Գ����ܿ� �ڽ� �Գ��� �ִ´�.
		vecBabyGenome.push_back(baby1);
		vecBabyGenome.push_back(baby2);

		iNewBabies += 2; // ���� ������ �ڽ� �Գ� ���� ����
	}

	// �� ���븦 ��ģ �� �̸�
	// �θ� �Գ� ������ ���ο� �ڽ� �Գ��������� �ٲ��ش�.
	vecGenomes = vecBabyGenome;

	// ���� ����
	++iGenteration;
}

int Genetic::GetGeneration() const
{
	return iGenteration;
}

void Genetic::Print(int i)
{
	{
		PrintMap(); // �ӽ�.
		CopyMap();
		cout << "ù��° ����ü : " << i + 1 << endl;
		cout << "���� : " << iGenteration << endl;
		cout << "���� ���� ������ : " << dBestFitnessScore << endl;
		cout << "���� ������ ���� ������ : ";
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
		PrintMap(); // �ӽ�.
		CopyMap();
		cout << "���� : " << iGenteration << endl;
		system("pause");
		system("cls");
	}
}