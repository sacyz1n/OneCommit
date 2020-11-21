#pragma once

/*
	���� ������������ ��ġ�ϱ�
	���� ����
	�Լ� solution�� ���� n�� �Ű������� �Է¹޽��ϴ�. n�� �� �ڸ����� ū�ͺ��� ���� ������ ������ ���ο� ������ �������ּ���. ������� n�� 118372�� 873211�� �����ϸ� �˴ϴ�.

	���� ����
	n�� 1�̻� 8000000000 ������ �ڿ����Դϴ�.

	����� ��
	n	return
	118372	873211
*/

#include <string>
#include <algorithm>

namespace sol_26
{
	long long solution(long long _n)
	{
		std::string str = std::to_string(_n);
		std::sort(str.begin(), str.end(), std::greater<char>());

		return atoll(str.c_str());
	}
}