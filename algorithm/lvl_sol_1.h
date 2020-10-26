#pragma once

#include <vector>
#include <string>
#include <map>
#include <algorithm>
/*
	���� ����
	���� �迭 numbers�� �־����ϴ�. 
	numbers���� ���� �ٸ� �ε����� �ִ� �� ���� ���� �̾� ���ؼ� ���� �� �ִ� ��� ���� �迭�� ������������ ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

	���ѻ���
	numbers�� ���̴� 2 �̻� 100 �����Դϴ�.
	numbers�� ��� ���� 0 �̻� 100 �����Դϴ�.

	����� ��
	numbers	result
	[2,1,3,4,1]	[2,3,4,5,6,7]
	[5,0,2,7]	[2,5,7,9,12]

	����� �� ����
	����� �� #1

	2 = 1 + 1 �Դϴ�. (1�� numbers�� �� �� �ֽ��ϴ�.)
	3 = 2 + 1 �Դϴ�.
	4 = 1 + 3 �Դϴ�.
	5 = 1 + 4 = 2 + 3 �Դϴ�.
	6 = 2 + 4 �Դϴ�.
	7 = 3 + 4 �Դϴ�.
	���� [2,3,4,5,6,7] �� return �ؾ� �մϴ�.

	����� �� #2

	2 = 0 + 2 �Դϴ�.
	5 = 5 + 0 �Դϴ�.
	7 = 0 + 7 = 5 + 2 �Դϴ�.
	9 = 2 + 7 �Դϴ�.
	12 = 5 + 7 �Դϴ�.
	���� [2,5,7,9,12] �� return �ؾ� �մϴ�.

*/

namespace sol_1
{

	using namespace std;

	vector<int> solution(vector<int> _numbers)
	{
		std::vector<int> answer;
		std::size_t size = _numbers.size();
		answer.reserve(size * size);

		bool bIsAnswer[200] = { false, };

		for (std::size_t i = 0; i < size; ++i)
		{
			for (std::size_t j = 0; j < size; ++j)
			{
				if (i == j)
					continue;

				int number = _numbers[i] + _numbers[j];

				if (bIsAnswer[number])
					continue;

				bIsAnswer[number] = true;
				answer.emplace_back(number);
			}
		}

		std::sort(answer.begin(), answer.end());

		return answer;
	}
}
