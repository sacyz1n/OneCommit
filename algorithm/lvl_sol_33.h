#pragma once

/*

*/

#include <vector>

namespace sol_33
{
	std::vector<int> solution(int _n, int _m)
	{
		if (_n < _m) 
		{
			int tmp = _n;
			_n = _m;
			_m = tmp;
		}

		int lcm = _m * _n;

		while (_m)
		{
			_n = _m;
			_m = _n % _m;
		}

		return { _n, lcm / _n };
	}
}