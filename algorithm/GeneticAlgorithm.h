#ifndef __GENETIC_ALGORITHM_H_
#define __GENETIC_ALGORITHM_H_

#include "Genome.h"

class Genetic
{
private:
	std::vector<Genome> vecGenomes; // 게놈의 집단
 
	int iPopSize;					// 게놈 집단의 크기
	int iChromoLenght;				// 염색체 당 비트수
	int iGeneLength;				// 유전자 당 비트수
	int iFittestGenome;				// 적응도가 가장 높은 게놈의 인덱스
	int iGenteration;				// 진화 횟수
	
	double dBestFitnessScore;		// 가장 높은 적응도
	double dTotalFitnessScore;		// 적응도의 총합 
	double dCrossoverRate;			// 교차율
	double dMutationRate;			// 변이율
	
	void CrossOver( // 교차 함수
		const std::vector<int>& _mum,
		const std::vector<int>& _dad,
		std::vector<int>&	    _baby1,
		std::vector<int>&	    _baby2 );

	// 돌연변이함수
	void Mutate(std::vector<int>& _vecBits);

	// 게놈들의 적응도를 갱신하고 
	// 가장 높은 적응도를 가진 게놈을 찾는다.
	void UpdateFitnessScores();

	// 유전자 정보 해석
	std::vector<int> Decode(const std::vector<int>& bit);

	// 비트들의 벡터를 십진수로 변환한다.
	int BinToInt(const std::vector<int>& v);

	// 임의의 일련의 비트들을 가지는 초기 게놈 집단 생성
	void CreateStartPopulation();

	// 염색체의 룰렛선택
	Genome& Roulette();
public:
	Genetic(double _CrossRate, double _MutRate, int _PopSize, int num_bit, int _GenLen);

	// 접근자
	int GetGeneration() const;
	//int GetFittest() const;

	// 시대
	void Epoch();

	// 임시로 만들어놓은거 삭제해야한다.
	void Print(int i);
	void Print();

	bool bCheckFitness;
};


#endif // !__GENETIC_ALGORITHM_H_