#pragma once

/*
	���ڿ� ����
	���� ����
	������ ó�� �������� �ǰ� ���� ����ġ�� ���ڿ��� �����ϴ� ����� ���� ���θ� �ϰ� �ֽ��ϴ�. �ֱٿ� �뷮�� ������ ó���� ���� ������ ��ս� ���� ����� ���� ���θ� �ϰ� �ִµ�, ���ڿ����� ���� ���� �����ؼ� ��Ÿ���� ���� �� ������ ������ �ݺ��Ǵ� ������ ǥ���Ͽ� �� ª�� ���ڿ��� �ٿ��� ǥ���ϴ� �˰����� �����ϰ� �ֽ��ϴ�.
	������ ���� aabbaccc�� ��� 2a2ba3c(���ڰ� �ݺ����� �ʾ� �ѹ��� ��Ÿ�� ��� 1�� ������)�� ���� ǥ���� �� �ִµ�, �̷��� ����� �ݺ��Ǵ� ���ڰ� ���� ��� ������� ���ٴ� ������ �ֽ��ϴ�. ���� ���, abcabcdede�� ���� ���ڿ��� ���� ������� �ʽ��ϴ�. ����ġ�� �̷��� ������ �ذ��ϱ� ���� ���ڿ��� 1�� �̻��� ������ �߶� �����Ͽ� �� ª�� ���ڿ��� ǥ���� �� �ִ��� ����� ã�ƺ����� �մϴ�.

	���� ���, ababcdcdababcdcd�� ��� ���ڸ� 1�� ������ �ڸ��� ���� ������� ������, 2�� ������ �߶� �����Ѵٸ� 2ab2cd2ab2cd�� ǥ���� �� �ֽ��ϴ�. �ٸ� ������� 8�� ������ �߶� �����Ѵٸ� 2ababcdcd�� ǥ���� �� ������, �̶��� ���� ª�� �����Ͽ� ǥ���� �� �ִ� ����Դϴ�.

	�ٸ� ����, abcabcdede�� ���� ���, ���ڸ� 2�� ������ �߶� �����ϸ� abcabc2de�� ������, 3�� ������ �ڸ��ٸ� 2abcdede�� �Ǿ� 3�� ������ ���� ª�� ���� ����� �˴ϴ�. �̶� 3�� ������ �ڸ��� �������� ���� ���ڿ��� �״�� �ٿ��ָ� �˴ϴ�.

	������ ���ڿ� s�� �Ű������� �־��� ��, ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶� �����Ͽ� ǥ���� ���ڿ� �� ���� ª�� ���� ���̸� return �ϵ��� solution �Լ��� �ϼ����ּ���.

	���ѻ���
	s�� ���̴� 1 �̻� 1,000 �����Դϴ�.
	s�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

	����� ��
	s	result
	"aabbaccc"	7
	"ababcdcdababcdcd"	9
	"abcabcdede"	8
	"abcabcabcabcdededededede"	14
	"xababcdcdababcdcd"	17
	����� ���� ���� ����
	����� �� #1

	���ڿ��� 1�� ������ �߶� �������� �� ���� ª���ϴ�.

	����� �� #2

	���ڿ��� 8�� ������ �߶� �������� �� ���� ª���ϴ�.

	����� �� #3

	���ڿ��� 3�� ������ �߶� �������� �� ���� ª���ϴ�.

	����� �� #4

	���ڿ��� 2�� ������ �ڸ��� abcabcabcabc6de �� �˴ϴ�.
	���ڿ��� 3�� ������ �ڸ��� 4abcdededededede �� �˴ϴ�.
	���ڿ��� 4�� ������ �ڸ��� abcabcabcabc3dede �� �˴ϴ�.
	���ڿ��� 6�� ������ �ڸ� ��� 2abcabc2dedede�� �Ǹ�, �̶��� ���̰� 14�� ���� ª���ϴ�.

	����� �� #5

	���ڿ��� ���� �պ��� ������ ���̸�ŭ �߶�� �մϴ�.
	���� �־��� ���ڿ��� x / ababcdcd / ababcdcd �� �ڸ��� ���� �Ұ��� �մϴ�.
	�� ��� ��� ���ڿ��� �߶� ������� �����Ƿ� ���� ª�� ���̴� 17�� �˴ϴ�.

*/

#include <string>

using namespace std;

namespace lvl2_sol_1
{
	int solution(string s) {

		std::string answer;

		int len = 1;
		std::size_t stringLen = s.length();

		int compressionCnt = stringLen;

		// ���ڿ��� ������ ����
		for (int len = 1; len <= stringLen; ++len)
		{
			// ����� ���ڿ�
			std::string resultString = "";

			int curCnt = 1;
			std::string curString = s.substr(0, len);

			for (int i = len; i < stringLen; i += len)
			{
				std::string newString = s.substr(i, len);

				if (curString == newString)
				{
					++curCnt;
					continue;
				}

				resultString += (curCnt > 1 ? std::to_string(curCnt) : "") + curString;
				curString = newString;
				curCnt = 1;
			}

			resultString += (curCnt > 1 ? std::to_string(curCnt) : "") + curString;

			// ������ ���ڿ� ����
			int resultStrLen = resultString.length();

			if (resultStrLen < compressionCnt)
				compressionCnt = resultStrLen;
		}

		return compressionCnt;
	}
}