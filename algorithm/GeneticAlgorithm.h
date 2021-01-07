#ifndef __GENETIC_ALGORITHM_H_
#define __GENETIC_ALGORITHM_H_

#include "Genome.h"

class Genetic
{
private:
	std::vector<Genome> vecGenomes; // �Գ��� ����
 
	int iPopSize;					// �Գ� ������ ũ��
	int iChromoLenght;				// ����ü �� ��Ʈ��
	int iGeneLength;				// ������ �� ��Ʈ��
	int iFittestGenome;				// �������� ���� ���� �Գ��� �ε���
	int iGenteration;				// ��ȭ Ƚ��
	
	double dBestFitnessScore;		// ���� ���� ������
	double dTotalFitnessScore;		// �������� ���� 
	double dCrossoverRate;			// ������
	double dMutationRate;			// ������
	
	void CrossOver( // ���� �Լ�
		const std::vector<int>& _mum,
		const std::vector<int>& _dad,
		std::vector<int>&	    _baby1,
		std::vector<int>&	    _baby2 );

	// ���������Լ�
	void Mutate(std::vector<int>& _vecBits);

	// �Գ���� �������� �����ϰ� 
	// ���� ���� �������� ���� �Գ��� ã�´�.
	void UpdateFitnessScores();

	// ������ ���� �ؼ�
	std::vector<int> Decode(const std::vector<int>& bit);

	// ��Ʈ���� ���͸� �������� ��ȯ�Ѵ�.
	int BinToInt(const std::vector<int>& v);

	// ������ �Ϸ��� ��Ʈ���� ������ �ʱ� �Գ� ���� ����
	void CreateStartPopulation();

	// ����ü�� �귿����
	Genome& Roulette();
public:
	Genetic(double _CrossRate, double _MutRate, int _PopSize, int num_bit, int _GenLen);

	// ������
	int GetGeneration() const;
	//int GetFittest() const;

	// �ô�
	void Epoch();

	// �ӽ÷� ���������� �����ؾ��Ѵ�.
	void Print(int i);
	void Print();

	bool bCheckFitness;
};


#endif // !__GENETIC_ALGORITHM_H_