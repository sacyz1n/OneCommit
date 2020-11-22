#pragma once

/*
	���� ������ �Ǻ�
	���� ����
	������ ���� ���� n�� ����, n�� � ���� ���� x�� �������� �ƴ��� �Ǵ��Ϸ� �մϴ�.
	n�� ���� ���� x�� �����̶�� x+1�� ������ �����ϰ�, n�� ���� ���� x�� ������ �ƴ϶�� -1�� �����ϴ� �Լ��� �ϼ��ϼ���.

	���� ����
	n�� 1�̻�, 50000000000000 ������ ���� �����Դϴ�.

	����� ��
	n	return
	121	144
	3	-1

	����� �� ����

	����� ��#1
	121�� ���� ���� 11�� �����̹Ƿ�, (11+1)�� ������ 144�� �����մϴ�.

	����� ��#2
	3�� ���� ������ ������ �ƴϹǷ�, -1�� �����մϴ�.
*/

#include <cmath>

namespace sol_27
{
	long long solution(long long _n)
	{
		long double num = std::sqrtl(_n);

		if (num - static_cast<long long>(num) > 0.0)
			return -1;

		return static_cast<long long>(powl(static_cast<long long>(num), 2));
	}
}