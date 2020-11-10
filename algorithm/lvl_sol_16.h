#pragma once

/*
	�Ҽ� ã��
	���� ����
	1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.

	�Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
	(1�� �Ҽ��� �ƴմϴ�.)

	���� ����
	n�� 2�̻� 1000000������ �ڿ����Դϴ�.

	����� ��
	n	result
	10	4
	5	3

	����� �� ����

	����� �� #1
	1���� 10 ������ �Ҽ��� [2,3,5,7] 4���� �����ϹǷ� 4�� ��ȯ

	����� �� #2
	1���� 5 ������ �Ҽ��� [2,3,5] 3���� �����ϹǷ� 3�� ��ȯ

*/

#include <vector>

namespace sol_16
{
	int solution(int _n)
	{
		std::vector<int> primes(_n + 1, true);

		int cnt = 0;

		for (std::size_t i = 2; i < primes.size(); ++i)
		{
			if (!primes[i])
				continue;

			for (int j = i + i; j < primes.size(); j += i)
				primes[j] = false;
		}

		for (std::size_t i = 2; i < primes.size(); ++i)
		{
			if (primes[i])
				++cnt;
		}

		return cnt;
	}
}