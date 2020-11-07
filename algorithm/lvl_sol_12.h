#pragma once


/*
	���￡�� �輭�� ã��

	���� ����
	String�� �迭 seoul�� element�� Kim�� ��ġ x�� ã��, �輭���� x�� �ִٴ� String�� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���. seoul�� Kim�� ���� �� ���� ��Ÿ���� �߸��� ���� �ԷµǴ� ���� �����ϴ�.

	���� ����
	seoul�� ���� 1 �̻�, 1000 ������ �迭�Դϴ�.
	seoul�� ���Ҵ� ���� 1 �̻�, 20 ������ ���ڿ��Դϴ�.
	Kim�� �ݵ�� seoul �ȿ� ���ԵǾ� �ֽ��ϴ�.

	����� ��
	seoul	return
	[Jane, Kim]	

*/

#include <string>
#include <vector>
#include <algorithm>

namespace sol_12
{
	std::string solution(std::vector<std::string> _seoul)
	{
		for (std::size_t i = 0; i < _seoul.size(); ++i)
		{
			if (!_seoul[i].compare("Kim"))
				return "�輭���� " + std::to_string(i) + "�� �ִ�";
		}

		return "";
	}
}