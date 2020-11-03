#pragma once

#include <vector>
#include <iostream>

namespace sol_8
{
	std::vector<int> solution(std::vector<int> _arr)
	{
		std::vector<int> answer;

		answer.reserve(_arr.size());

		int curNum = -1;

		for (std::size_t i = 0; i < _arr.size(); ++i)
		{
			if (curNum == _arr[i])
				continue;

			curNum = _arr[i];
			answer.push_back(curNum);
		}

		return answer;
	}
}