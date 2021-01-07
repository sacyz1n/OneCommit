#include "Genome.h"


Genome::Genome() : dFitness(0) { }

Genome::Genome(const int num_bits) : dFitness(0)
{
	for (int i = 0; i < num_bits; i++)
	{
		// 임의의 유전자 입력
		vecBits.push_back(rand() % 2); 
	}
}

std::vector<int> Genome::GetBits() const
{
	return vecBits;
}

void Genome::SetFitness(double _dFitness)
{
	dFitness = _dFitness;
}

double Genome::GetFitness() const
{
	return dFitness;
}