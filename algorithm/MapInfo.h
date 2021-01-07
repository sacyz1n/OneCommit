#ifndef __MAP_INFO_H_
#define __MAP_INFO_H_


#include <iostream>
#include <vector>
// �� ����
#define WIDTH  15
#define HEIGHT 10

using namespace std;

// ���� ��ġ
int iStartX = 14;
int iStartY = 7;

// ������ ��ġ
int iEndX = 0;
int iEndY = 2;


static int iMapArr[HEIGHT][WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
	{ 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5 },
	{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

static int iCopyMap[HEIGHT][WIDTH] =
{
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
{ 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
{ 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5 },
{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void CopyMap()
{
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			iCopyMap[i][j] = iMapArr[i][j];
}

void PrintMap()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			switch (iCopyMap[i][j])
			{
			case 1:
				cout << "��";
				break;
			case 0:
				cout << "  ";
				break;
			case 5:
				cout << " S";
				break;
			case 6:
				cout << "��";
				break;
			case 8:
				cout << " E";
				break;
			}

		}
		cout << endl;
	}
}


double TestRoute(const std::vector<int>& vecPath)
{
	// ���� ��ġ�� ������������ �ʱ�ȭ
	int iPosX = iStartX;
	int iPosY = iStartY;

	for (unsigned int i = 0; i < vecPath.size(); i++)
	{
		int iNextDirection = vecPath[i]; // ���� ��ġ ����

		switch (iNextDirection)
		{
		case 0: // ����
			if (((iPosY - 1) < 0) || (iMapArr[iPosY - 1][iPosX] == 1)) // ���� ���� ���, ���� �������� �� ������ ���
				break;
			else
			{
				iPosY -= 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 1: // ����
			if (((iPosY + 1) >= HEIGHT) || (iMapArr[iPosY + 1][iPosX] == 1))
				break;
			else
			{
				iPosY += 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 2: // ����
			if (((iPosX + 1) >= WIDTH) || (iMapArr[iPosY][iPosX + 1] == 1))
				break;
			else
			{
				iPosX += 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 3: // ����
			if (((iPosX - 1) < 0) || (iMapArr[iPosY][iPosX - 1] == 1))
				break;
			else
			{
				iPosX -= 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		}
	}




	int DistanceX = abs(iPosX - iEndX);
	int DistanceY = abs(iPosY - iEndY);

	return 1 / double(DistanceX + DistanceY + 1); // ������ ��� �� ��ȯ
}

#endif // !__MAP_INFO_H_