#ifndef __Genome_H_
#define __Genome_H_

#include <vector>

class Genome
{
public:
	std::vector<int> vecBits; // 염색체가 가지는 유전자
	double dFitness;		  // 염색체의 적응도
public:
	Genome();
	Genome(const int num_bits);
	std::vector<int> GetBits() const;
	void SetFitness(double _dFitness);
	double GetFitness() const;
};


#endif // !__Genome_H_
