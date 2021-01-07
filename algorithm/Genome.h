#ifndef __Genome_H_
#define __Genome_H_

#include <vector>

class Genome
{
public:
	std::vector<int> vecBits; // ����ü�� ������ ������
	double dFitness;		  // ����ü�� ������
public:
	Genome();
	Genome(const int num_bits);
	std::vector<int> GetBits() const;
	void SetFitness(double _dFitness);
	double GetFitness() const;
};


#endif // !__Genome_H_
