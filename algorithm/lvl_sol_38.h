#pragma once

/*
	x��ŭ ������ �ִ� n���� ����
	���� ����
	�Լ� solution�� ���� x�� �ڿ��� n�� �Է� �޾�, x���� ������ x�� �����ϴ� ���ڸ� n�� ���ϴ� ����Ʈ�� �����ؾ� �մϴ�. ���� ���� ������ ����, ������ �����ϴ� �Լ�, solution�� �ϼ����ּ���.

	���� ����
	x�� -10000000 �̻�, 10000000 ������ �����Դϴ�.
	n�� 1000 ������ �ڿ����Դϴ�.
	����� ��
	x	n	answer
	2	5	[2,4,6,8,10]
	4	3	[4,8,12]
	-4	2	[-4, -8]
*/

#include <vector>

namespace sol_38
{
	std::vector<long long> solution(int _x, int _n) 
	{
		std::vector<long long> answer(_n);

		for (int i = 0, num = _x; i < _n; ++i, num += _x)
			answer[i] = num;

		return std::move(answer);
	}
}