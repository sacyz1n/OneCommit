#pragma once


/*
	���� ���� �� �����ϱ�
	���� ����
	������ ������ �迭, arr ���� ���� ���� ���� ������ �迭�� �����ϴ� �Լ�, solution�� �ϼ����ּ���. ��, �����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� �����ϼ���. ������� arr�� [4,3,2,1]�� ���� [4,3,2]�� ���� �ϰ�, [10]�� [-1]�� ���� �մϴ�.

	���� ����
	arr�� ���� 1 �̻��� �迭�Դϴ�.
	�ε��� i, j�� ���� i �� j�̸� arr[i] �� arr[j] �Դϴ�.

	����� ��
	arr	return
	[4,3,2,1]	[4,3,2]
	[10]	[-1]
*/

#include <vector>
#include <string>
#include <algorithm>

namespace sol_28
{
	std::vector<int> solution(std::vector<int> _arr)
	{
		_arr.erase(std::min_element(_arr.begin(), _arr.end()));

		if (_arr.empty())
			_arr.emplace_back(-1);

		return _arr;
	}
}