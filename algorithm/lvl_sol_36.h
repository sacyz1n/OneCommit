#pragma once

/*
	���簢�� �����
	���� ����
	�� �������� ǥ�� �Է����� �� ���� ���� n�� m�� �־����ϴ�.
	��(*) ���ڸ� �̿��� ������ ���̰� n, ������ ���̰� m�� ���簢�� ���¸� ����غ�����.

	���� ����
	n�� m�� ���� 1000 ������ �ڿ����Դϴ�.
	����
	�Է�

	5 3
	���

	*****
	*****
	*****
*/

#include <iostream>

namespace sol_36
{
	int solution(void) {
		int a = 0, b = 0;
		std::cin >> a >> b;

		for (int j = 0; j < a; ++j)
		{
			for (int i = 0; i < b; ++i)
				std::cout << "*";

			std::cout << std::endl;
		}

		return 0;
	}
}