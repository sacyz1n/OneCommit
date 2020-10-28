#pragma once

#include <vector>
#include <algorithm>
/*
	���� ����
	�迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�.

	���� ��� array�� [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��

	array�� 2��°���� 5��°���� �ڸ��� [5, 2, 6, 3]�Դϴ�.
	1���� ���� �迭�� �����ϸ� [2, 3, 5, 6]�Դϴ�.
	2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�.
	�迭 array, [i, j, k]�� ���ҷ� ���� 2���� �迭 commands�� �Ű������� �־��� ��, commands�� ��� ���ҿ� ���� �ռ� ������ ������ �������� �� ���� ����� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	array�� ���̴� 1 �̻� 100 �����Դϴ�.
	array�� �� ���Ҵ� 1 �̻� 100 �����Դϴ�.
	commands�� ���̴� 1 �̻� 50 �����Դϴ�.
	commands�� �� ���Ҵ� ���̰� 3�Դϴ�.

	����� ��
	array	commands	return
	[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
	����� �� ����
	[1, 5, 2, 6, 3, 7, 4]�� 2��°���� 5��°���� �ڸ� �� �����մϴ�. [2, 3, 5, 6]�� �� ��° ���ڴ� 5�Դϴ�.
	[1, 5, 2, 6, 3, 7, 4]�� 4��°���� 4��°���� �ڸ� �� �����մϴ�. [6]�� ù ��° ���ڴ� 6�Դϴ�.
	[1, 5, 2, 6, 3, 7, 4]�� 1��°���� 7��°���� �ڸ��ϴ�. [1, 2, 3, 4, 5, 6, 7]�� �� ��° ���ڴ� 3�Դϴ�.

*/

namespace sol_2
{
	std::vector<int> solution(std::vector<int> _array, std::vector<std::vector<int>> _commands)
	{
		std::size_t size = _commands.size();

		std::vector<int> answer(size);

		for (std::size_t i = 0; i < size; ++i)
		{
			int cutSize = _commands[i][1] - _commands[i][0] + 1;

			std::vector<int> cutArray(std::make_move_iterator(_array.begin() + _commands[i][0] - 1),
									  std::make_move_iterator(_array.begin() + _commands[i][1]));

			std::sort(cutArray.begin(), cutArray.end());

			answer[i] = cutArray[_commands[i][2] - 1];
		}

		return answer;
	}
}