#pragma once

/*
	���� ��ȣ
	���� ����
	� ������ �� ���ĺ��� ������ �Ÿ���ŭ �о �ٸ� ���ĺ����� �ٲٴ� ��ȣȭ ����� ���� ��ȣ��� �մϴ�. ���� ��� AB�� 1��ŭ �и� BC�� �ǰ�, 3��ŭ �и� DE�� �˴ϴ�. z�� 1��ŭ �и� a�� �˴ϴ�. ���ڿ� s�� �Ÿ� n�� �Է¹޾� s�� n��ŭ �� ��ȣ���� ����� �Լ�, solution�� �ϼ��� ������.

	���� ����
	������ �ƹ��� �о �����Դϴ�.
	s�� ���ĺ� �ҹ���, �빮��, �������θ� �̷���� �ֽ��ϴ�.
	s�� ���̴� 8000�����Դϴ�.
	n�� 1 �̻�, 25������ �ڿ����Դϴ�.

	����� ��
	s	n	result
	AB	1	BC
	z	1	a
	a B z	4	e F d
*/

#include <string>
#include <vector>

namespace sol_20
{
	std::string solution(std::string _s, int _n)
	{
		for (int i = 0; i < _s.length(); ++i)
		{
			if (_s[i] == ' ')
				continue;

			char checkChar = 0;

			if (isupper(_s[i]))
				checkChar = 'Z';
			else
				checkChar = 'z';

			unsigned char answerChar = _s[i] + _n;

			_s[i] = (answerChar > checkChar ? (answerChar - checkChar) + checkChar - 26 : answerChar);
		}
		return _s;
	}
}