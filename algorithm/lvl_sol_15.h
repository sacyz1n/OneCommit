#pragma once

/*
	���ڿ� ������������ ��ġ�ϱ�

	���� ����
	���ڿ� s�� ��Ÿ���� ���ڸ� ū�ͺ��� ���� ������ ������ ���ο� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
	s�� ���� ��ҹ��ڷθ� �����Ǿ� ������, �빮�ڴ� �ҹ��ں��� ���� ������ �����մϴ�.

	���� ����
	str�� ���� 1 �̻��� ���ڿ��Դϴ�.

	����� ��
	s		return
	Zbcdefg	gfedcbZ
*/

#include <string>
#include <vector>
#include <algorithm>

namespace sol_15
{
	std::string solution(std::string _s)
	{
		std::sort(_s.begin(), _s.end(), std::greater<char>());
		return _s;
	}
}