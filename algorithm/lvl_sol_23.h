#pragma once

/*
	�̻��� ���� �����
	���� ����
	���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. �� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. �� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.

	���� ����
	���ڿ� ��ü�� ¦/Ȧ�� �ε����� �ƴ϶�, �ܾ�(������ ����)���� ¦/Ȧ�� �ε����� �Ǵ��ؾ��մϴ�.
	ù ��° ���ڴ� 0��° �ε����� ���� ¦����° ���ĺ����� ó���ؾ� �մϴ�.

	����� ��
	s	return
	try hello world	TrY HeLlO WoRlD

	����� �� ����
	try hello world�� �� �ܾ� try, hello, world�� �����Ǿ� �ֽ��ϴ�. �� �ܾ��� ¦����° ���ڸ� �빮�ڷ�, Ȧ����° ���ڸ� �ҹ��ڷ� �ٲٸ� TrY, HeLlO, WoRlD�Դϴ�. ���� TrY HeLlO WoRlD �� �����մϴ�.

*/

#include <string>
#include <algorithm>

namespace sol_23
{
	std::string solution(std::string _s)
	{
		int num = 1;
		for (std::size_t i = 0; i < _s.length(); ++i)
		{
			if (_s[i] == ' ')
			{
				num = 1;
				continue;
			}

			// ¦���� ���
			if (num % 2 == 0)
				_s[i] = ::tolower(_s[i]);
			else
				_s[i] = toupper(_s[i]);

			++num;
		}
		return _s;
	}
}