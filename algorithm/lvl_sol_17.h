#pragma once

/*
	���ڼ��ڼ��ڼ��ڼ��ڼ�?
	���� ����
	���̰� n�̰�, ���ڼ��ڼ��ڼ�....�� ���� ������ �����ϴ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���. ������� n�� 4�̸� ���ڼ����� �����ϰ� 3�̶�� ���ڼ��� �����ϸ� �˴ϴ�.

	���� ����
	n�� ���� 10,000������ �ڿ����Դϴ�.
	����� ��
	n	return
	3	���ڼ�
	4	���ڼ���
	
*/

#include <string>

namespace sol_17
{
	std::string solution(int _n)
	{
		std::string answer = "";

		int n = 0;

		while (n++ < _n) { answer.append(n % 2 ? "��" : "��"); }

		return answer;
	}
}