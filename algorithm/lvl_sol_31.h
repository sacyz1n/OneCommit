#pragma once

/*
	�ڵ��� ��ȣ ������
	���� ����
	���α׷��ӽ� ������� �������� ��ȣ�� ���� �������� ���� �� ������ ��ȭ��ȣ�� �Ϻθ� �����ϴ�.
	��ȭ��ȣ�� ���ڿ� phone_number�� �־����� ��, ��ȭ��ȣ�� �� 4�ڸ��� ������ ������ ���ڸ� ���� *���� ���� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

	���� ����
	s�� ���� 4 �̻�, 20������ ���ڿ��Դϴ�.

	����� ��
	phone_number	return
	01033334444	*******4444
	027778888	*****8888
*/

#include <string>
#include <algorithm>

namespace sol_31
{
	std::string solution(std::string _phoneNumber)
	{
		for (std::size_t i = 0; i < _phoneNumber.length() - 4; ++i)
			_phoneNumber[i] = '*';

		return _phoneNumber;
	}
}