#pragma once

/*
	���ڿ� �� p�� y�� ����

	���� ����
	�빮�ڿ� �ҹ��ڰ� �����ִ� ���ڿ� s�� �־����ϴ�. s�� 'p'�� ������ 'y'�� ������ ���� ������ True, �ٸ��� False�� return �ϴ� solution�� �ϼ��ϼ���. 'p', 'y' ��� �ϳ��� ���� ���� �׻� True�� �����մϴ�. ��, ������ ���� �� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.

	���� ��� s�� pPoooyY�� true�� return�ϰ� Pyy��� false�� return�մϴ�.

	���ѻ���
	���ڿ� s�� ���� : 50 ������ �ڿ���
	���ڿ� s�� ���ĺ����θ� �̷���� �ֽ��ϴ�.

	����� ��
	s	answer
	pPoooyY	true
	Pyy	false

	����� �� ����

	����� �� #1
	'p'�� ���� 2��, 'y'�� ���� 2���� �����Ƿ� true�� return �մϴ�.

	����� �� #2
	'p'�� ���� 1��, 'y'�� ���� 2���� �ٸ��Ƿ� false�� return �մϴ�.
*/

#include <iostream>
#include <string>
#include <algorithm>

namespace sol_14
{
	bool solution(std::string _s)
	{
		int cnt = 0;
		std::for_each(_s.begin(), _s.end(), [&](char& _c)
		{
			switch (_c)
			{
			case 'P':
			case 'p':
				--cnt;
				break;
			case 'Y':
			case 'y':
				++cnt;
				break;
			}
		});

		return !cnt;
	}
}