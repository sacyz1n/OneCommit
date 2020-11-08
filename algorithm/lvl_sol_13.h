#pragma once

/*
	���ڿ� �ٷ�� �⺻

	���� ����
	���ڿ� s�� ���̰� 4 Ȥ�� 6�̰�, ���ڷθ� �������ִ��� Ȯ�����ִ� �Լ�, solution�� �ϼ��ϼ���. ���� ��� s�� a234�̸� False�� �����ϰ� 1234��� True�� �����ϸ� �˴ϴ�.

	���� ����
	s�� ���� 1 �̻�, ���� 8 ������ ���ڿ��Դϴ�.

	����� ��
	s	return
	a234	false
	1234	true

*/

#include <string>

namespace sol_13
{
	bool solution(std::string _s)
	{
		std::size_t len = _s.length();

		if (len == 4 || len == 6)
		{
			for (std::size_t i = 0; i < len; ++i)
			{
				if (_s[i] < '0' || _s[i] > '9')
					return false;
			}
			return true;
		}
		return false;
	}
}