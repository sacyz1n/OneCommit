#pragma once

/*
	��ųƮ��
	���� ����
	���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.

	���� ��� ���� ��ų ������ ����ũ �� ����Ʈ�� ��Ʈ �� ����϶�, ����� ������ ���� ����Ʈ�� ��Ʈ�� ����� �ϰ�, ����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.

	�� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�. ���� ����ũ �� ���� �� ����Ʈ�� ��Ʈ �� ����� ���� ��ųƮ���� ����������, ��� �� ����ũ�� ����Ʈ�� ��Ʈ �� ����ũ �� ���� �� ����� ���� ��ųƮ���� �Ұ����մϴ�.

	���� ��ų ���� skill�� �������� ���� ��ųƮ��1�� ���� �迭 skill_trees�� �Ű������� �־��� ��, ������ ��ųƮ�� ������ return �ϴ� solution �Լ��� �ۼ����ּ���.

	���� ����
	��ų�� ���ĺ� �빮�ڷ� ǥ���ϸ�, ��� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
	��ų ������ ��ųƮ���� ���ڿ��� ǥ���մϴ�.
	���� ���, C �� B �� D ��� CBD�� ǥ���մϴ�
	���� ��ų ���� skill�� ���̴� 1 �̻� 26 �����̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
	skill_trees�� ���� 1 �̻� 20 ������ �迭�Դϴ�.
	skill_trees�� ���Ҵ� ��ų�� ��Ÿ���� ���ڿ��Դϴ�.
	skill_trees�� ���Ҵ� ���̰� 2 �̻� 26 ������ ���ڿ��̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
	����� ��
	skill	skill_trees	return
	"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2
	����� �� ����
	BACDE: B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���ϴ�.
	CBADF: ������ ��ųƮ���Դϴ�.
	AECB: ������ ��ųƮ���Դϴ�.
	BDA: B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���Դϴ�.

*/
#include <string>
#include <vector>
#include <algorithm>

namespace lvl2_sol_3
{
	using namespace std;

	int solution(string skill, vector<string> skill_trees) {
		int answer = 0;

		for_each(skill_trees.begin(), skill_trees.end(), [&](auto& _skill)
		{
			bool isFirstCheck = true;
			size_t index = 0;
			for (int len = skill.length() - 1; len >= 0; --len)
			{
				size_t findIdx = _skill.find(skill[len]);

				if (isFirstCheck)
				{
					if (std::string::npos == findIdx)
						continue;

					index = findIdx;
					isFirstCheck = false;
					continue;
				}
				
				if (std::string::npos == findIdx || index < findIdx)
					return;

				index = findIdx;
			}

			++answer;
		});

		return answer;
	}
}