#pragma once

/*
	������ �������� ���� �迭
	���� ����
	array�� �� element �� divisor�� ������ �������� ���� ������������ ������ �迭�� ��ȯ�ϴ� �Լ�, solution�� �ۼ����ּ���.
	divisor�� ������ �������� element�� �ϳ��� ���ٸ� �迭�� -1�� ��� ��ȯ�ϼ���.
	
	���ѻ���
	arr�� �ڿ����� ���� �迭�Դϴ�.
	���� i, j�� ���� i �� j �̸� arr[i] �� arr[j] �Դϴ�.
	divisor�� �ڿ����Դϴ�.
	array�� ���� 1 �̻��� �迭�Դϴ�.

	����� ��
	arr	divisor	return
	[5, 9, 7, 10]	5	[5, 10]
	[2, 36, 1, 3]	1	[1, 2, 3, 36]
	[3,2,6]	10	[-1]

	����� �� ����
	����� ��#1
	arr�� ���� �� 5�� ������ �������� ���Ҵ� 5�� 10�Դϴ�. ���� [5, 10]�� �����մϴ�.
	
	����� ��#2
	arr�� ��� ���Ҵ� 1���� ������ �������ϴ�. ���Ҹ� ������������ ������ [1, 2, 3, 36]�� �����մϴ�.
	
	����� ��#3
	3, 2, 6�� 10���� ������ �������� �ʽ��ϴ�. ������ �������� ���Ұ� �����Ƿ� [-1]�� �����մϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

namespace sol_9
{
	std::vector<int> solution(std::vector<int> _arr, int _divisor)
	{
		std::vector<int> answer;
		answer.reserve(_arr.size());
		
		for (std::size_t i = 0; i < _arr.size(); ++i)
		{
			if (!(_arr[i] % _divisor))
				answer.emplace_back(_arr[i]);
		}

		if (answer.empty())
			answer.emplace_back(-1);
		else
			std::sort(answer.begin(), answer.end());

		return answer;
	}
}