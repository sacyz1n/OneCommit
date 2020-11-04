#pragma once

/*
	�� ���� ������ ��
	���� ����
	�� ���� a, b�� �־����� �� a�� b ���̿� ���� ��� ������ ���� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.
	���� ��� a = 3, b = 5�� ���, 3 + 4 + 5 = 12�̹Ƿ� 12�� �����մϴ�.

	���� ����
	a�� b�� ���� ���� �� �� �ƹ� ���� �����ϼ���.
	a�� b�� -10,000,000 �̻� 10,000,000 ������ �����Դϴ�.
	a�� b�� ��Ұ���� ���������� �ʽ��ϴ�.

	����� ��
	a	b	return
	3	5	12
	3	3	3
	5	3	12

*/

#include <string>
#include <vector>
#include <cmath>

namespace sol_10
{
	long long solution(int a, int b) 
	{
		return static_cast<long long>(((a + b) / 2.0) * (std::llabs(b - a) + 1));
	}
}