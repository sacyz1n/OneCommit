#pragma once

/*
	3���� ������
	���� ����
	�ڿ��� n�� �Ű������� �־����ϴ�. n�� 3���� �󿡼� �յڷ� ������ ��, �̸� �ٽ� 10�������� ǥ���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

	���ѻ���
	n�� 1 �̻� 100,000,000 ������ �ڿ����Դϴ�.

	����� ��
	n	result
	45	7
	125	229

	����� �� ����

	����� �� #1
	���� �����ϴ� ������ ������ �����ϴ�.
	n (10����)	n (3����)	�յ� ����(3����)	10�������� ǥ��
	45	1200	0021	7
	���� 7�� return �ؾ� �մϴ�.

	����� �� #2
	���� �����ϴ� ������ ������ �����ϴ�.
	n (10����)	n (3����)	�յ� ����(3����)	10�������� ǥ��
	125	11122	22111	229
	���� 229�� return �ؾ� �մϴ�.


*/

#include <string>
#include <vector>
#include <cmath>

namespace sol_7
{
	int solution(int _n)
	{
		int answer = 0;

		std::vector<int> nums;

		while (true)
		{
			nums.push_back(_n % 3);
			_n /= 3;

			if (_n < 3)
			{
				if (_n > 0)
					nums.push_back(_n);
				break;
			}
		}

		for (int i = nums.size() - 1, j = 0; i >= 0; --i, ++j)
			answer += nums[j] * static_cast<int>(std::pow(3, i));

		return answer;
	}
}