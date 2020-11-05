#pragma once

/*
	���ڿ� �� ������� �����ϱ�
	���� ����
	���ڿ��� ������ ����Ʈ strings��, ���� n�� �־����� ��, �� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. ���� ��� strings�� [sun, bed, car]�̰� n�� 1�̸� �� �ܾ��� �ε��� 1�� ���� u, e, a�� strings�� �����մϴ�.

	���� ����
	strings�� ���� 1 �̻�, 50������ �迭�Դϴ�.
	strings�� ���Ҵ� �ҹ��� ���ĺ����� �̷���� �ֽ��ϴ�.
	strings�� ���Ҵ� ���� 1 �̻�, 100������ ���ڿ��Դϴ�.
	��� strings�� ������ ���̴� n���� Ů�ϴ�.
	�ε��� 1�� ���ڰ� ���� ���ڿ��� ���� �� ���, ���������� �ռ� ���ڿ��� ���ʿ� ��ġ�մϴ�.

	����� ��
	strings	n	return
	[sun, bed, car]	1	[car, bed, sun]
	[abce, abcd, cdx]	2	[abcd, abce, cdx]

	����� �� ����
	����� �� 1
	sun, bed, car�� 1��° �ε��� ���� ���� u, e, a �Դϴ�. �̸� �������� strings�� �����ϸ� [car, bed, sun] �Դϴ�.

	����� �� 2
	abce�� abcd, cdx�� 2��° �ε��� ���� c, c, x�Դϴ�. ���� ���� �Ŀ��� cdx�� ���� �ڿ� ��ġ�մϴ�. abce�� abcd�� ���������� �����ϸ� abcd�� �켱�ϹǷ�, ���� [abcd, abce, cdx] �Դϴ�.


*/

#include <string>
#include <vector>
#include <algorithm>

namespace sol_11
{
	std::vector<std::string> solution(std::vector<std::string> _strings, int _n)
	{
		std::sort(_strings.begin(), _strings.end(), 
			[&](std::string& _str1, std::string& _str2)
		{
			// �ε����� ���ڰ� ���� ���ڿ��� ���, ���������� �ռ� ���ڿ��� ���ʿ� ��ġ�Ѵ�.
			if (_str1[_n] == _str2[_n])
			{
				std::size_t len = _str1.length();
				for (std::size_t i = 0; i < len; ++i)
				{
					if (_str1[i] == _str2[i])
						continue;

					if (_str1[i] < _str2[i])
						return true;

					return false;
				}
			}

			return (_str1[_n] < _str2[_n]);
		});
		return _strings;
	}
}