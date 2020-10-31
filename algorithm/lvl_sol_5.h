#pragma once

/*
	2016��
	���� ����
	2016�� 1�� 1���� �ݿ����Դϴ�. 2016�� a�� b���� ���� �����ϱ��? �� �� a ,b�� �Է¹޾� 2016�� a�� b���� ���� �������� �����ϴ� �Լ�, solution�� �ϼ��ϼ���. ������ �̸��� �Ͽ��Ϻ��� ����ϱ��� ���� SUN,MON,TUE,WED,THU,FRI,SAT
	�Դϴ�. ���� ��� a=5, b=24��� 5�� 24���� ȭ�����̹Ƿ� ���ڿ� TUE�� ��ȯ�ϼ���.

	���� ����
	2016���� �����Դϴ�.
	2016�� a�� b���� ������ �ִ� ���Դϴ�. (13�� 26���̳� 2�� 45�ϰ��� ��¥�� �־����� �ʽ��ϴ�)

	����� ��
	a	b	result
	5	24

*/

#include <string>
#include <vector>

namespace sol_5
{
	std::string week[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
	int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	std::string solution(int _a, int _b)
	{
		int day = _b;

		for (int i = 0; i < _a - 1; ++i)
			day += days[i];

		return week[day % 7];
	}
}