#pragma once

/*
	¦���� Ȧ��
	���� ����
	���� num�� ¦���� ��� Even�� ��ȯ�ϰ� Ȧ���� ��� Odd�� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

	���� ����
	num�� int ������ �����Դϴ�.
	0�� ¦���Դϴ�.

	����� ��
	num	return
	3	Odd
	4	Even
*/

#include <string>

namespace sol_29
{
	std::string solution(int _num)
	{
		return (_num % 2 == 0 ? "Even" : "Odd");
	}
}