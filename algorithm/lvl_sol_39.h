#pragma once

/*
	����� ����
	���� ����
	����� ������ ��� ���� ũ�Ⱑ ���� �� ����� ���� ��, ���� ���� ���� ���� ���� ����� �˴ϴ�. 2���� ��� arr1�� arr2�� �Է¹޾�, ��� ������ ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

	���� ����
	��� arr1, arr2�� ��� ���� ���̴� 500�� ���� �ʽ��ϴ�.
	����� ��
	arr1	arr2	return
	[[1,2],[2,3]]	[[3,4],[5,6]]	[[4,6],[7,9]]
	[[1],[2]]	[[3],[4]]	[[4],[6]]
*/
#include <string>
#include <vector>

namespace sol_39
{
	using namespace std;

	vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
	{
		vector<vector<int>> answer(arr1.size());

		for (std::size_t i = 0; i < answer.capacity(); ++i)
		{
			for (std::size_t j = 0; j < arr1[i].size(); ++j)
				answer[i].push_back(arr1[i][j] + arr2[i][j]);
		}

		return answer;
	}
}