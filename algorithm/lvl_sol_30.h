#pragma once
/*
	��� ���ϱ�
	���� ����
	������ ��� �ִ� �迭 arr�� ��հ��� return�ϴ� �Լ�, solution�� �ϼ��غ�����.

	���ѻ���
	arr�� ���� 1 �̻�, 100 ������ �迭�Դϴ�.
	arr�� ���Ҵ� -10,000 �̻� 10,000 ������ �����Դϴ�.

	����� ��
	arr	return
	[1,2,3,4]	2.5
	[5,5]	5
*/

#include <vector>

namespace sol_30
{
	double solution(std::vector<int> _arr)
	{
		double answer = 0.0;

		for (int num : _arr)
			answer += num;

		return (answer / _arr.size());
	}
}