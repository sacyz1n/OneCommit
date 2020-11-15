#pragma once

/*
	����
	���� ����
	���̰� ���� �� 1���� ���� �迭 a, b�� �Ű������� �־����ϴ�. a�� b�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

	�̶�, a�� b�� ������ a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] �Դϴ�. (n�� a, b�� ����)

	���ѻ���
	a, b�� ���̴� 1 �̻� 1,000 �����Դϴ�.
	a, b�� ��� ���� -1,000 �̻� 1,000 �����Դϴ�.

	����� ��
	a	b	result
	[1,2,3,4]	[-3,-1,0,2]	3
	[-1,0,1]	[1,0,-1]	-2

	����� �� ����

	����� �� #1
	a�� b�� ������ 1*(-3) + 2*(-1) + 3*0 + 4*2 = 3 �Դϴ�.

	����� �� #2
	a�� b�� ������ (-1)*1 + 0*0 + 1*(-1) = -2 �Դϴ�.
*/

#include <vector>


namespace sol_21
{
	int solution(std::vector<int> _a, std::vector<int> _b)
	{
		std::size_t len = _a.size();
		int answer = 0;
		for (std::size_t i = 0; i < len; ++i)
			answer += _a[i] * _b[i];
		return answer;
	}
}