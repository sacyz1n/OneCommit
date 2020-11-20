#pragma once

/*
	�ڿ��� ������ �迭�� �����
	���� ����
	�ڿ��� n�� ������ �� �ڸ� ���ڸ� ���ҷ� ������ �迭 ���·� �������ּ���. ������� n�� 12345�̸� [5,4,3,2,1]�� �����մϴ�.

	���� ����
	n�� 10,000,000,000������ �ڿ����Դϴ�.

	����� ��
	n	return
	12345	[5,4,3,2,1]
*/

#include <vector>
#include <string>

namespace sol_25
{
	std::vector<int> solution(long long _n)
	{
		std::string str = std::to_string(_n);
		std::vector<int> answer;
		answer.reserve(str.length());

		for (auto rIter = str.rbegin(); rIter != str.rend(); ++rIter)
			answer.push_back(*rIter - '0');

		return answer;
	}
}