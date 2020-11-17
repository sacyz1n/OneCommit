#pragma once
/*
	����� ��
	���� ����
	���� n�� �Է¹޾� n�� ����� ��� ���� ���� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

	���� ����
	n�� 0 �̻� 3000������ �����Դϴ�.

	����� ��
	n	return
	12	28
	5	6

	����� �� ����

	����� �� #1
	12�� ����� 1, 2, 3, 4, 6, 12�Դϴ�. �̸� ��� ���ϸ� 28�Դϴ�.

	����� �� #2
	5�� ����� 1, 5�Դϴ�. �̸� ��� ���ϸ� 6�Դϴ�.
*/

#include <string>
#include <vector>

namespace sol_22
{
	int solution(int _n)
	{
		int answer = 0;
		for (int i = 1; i <= _n; ++i)
		{
			if (_n % i == 0)
				answer += i;
		}

		return answer;
	}
}