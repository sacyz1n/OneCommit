#pragma once

/*
	�ڸ��� ���ϱ�
	���� ����
	�ڿ��� N�� �־�����, N�� �� �ڸ����� ���� ���ؼ� return �ϴ� solution �Լ��� ����� �ּ���.
	������� N = 123�̸� 1 + 2 + 3 = 6�� return �ϸ� �˴ϴ�.

	���ѻ���
	N�� ���� : 100,000,000 ������ �ڿ���

	����� ��
	N	answer
	123	6
	987	24

	����� �� ����

	����� �� #1
	������ ���ÿ� �����ϴ�.

	����� �� #2
	9 + 8 + 7 = 24�̹Ƿ� 24�� return �ϸ� �˴ϴ�.
*/

#include <string>

namespace sol_24
{
	int solution(int _n)
	{
		std::string str = std::to_string(_n);

		int sum = 0;

		for (std::size_t i = 0; i < str.length(); ++i)
			sum += str[i] - '0';

		return sum;
	}
}