#pragma once

/*
	��� ���� ��������
	���� ����
	�ܾ� s�� ��� ���ڸ� ��ȯ�ϴ� �Լ�, solution�� ����� ������. �ܾ��� ���̰� ¦����� ��� �α��ڸ� ��ȯ�ϸ� �˴ϴ�.

	���ѻ���
	s�� ���̰� 1 �̻�, 100������ ��Ʈ���Դϴ�.

	����� ��
	string	return
	abcde	c
	qwer	we
*/

#include <string>
#include <vector>

namespace sol_6
{
	std::string solution(std::string _s) {
		std::string answer = "";
		int length = _s.length();

		// Ȧ���� ���
		if (length % 2)
			answer = _s[length / 2];
		else
			answer = _s.substr(length / 2 - 1, 2);

		return answer;
	}
}