#ifndef __MAP_INFO_H_
#define __MAP_INFO_H_


#include <iostream>
#include <vector>
// 맵 넓이
#define WIDTH  15
#define HEIGHT 10

using namespace std;

// 시작 위치
int iStartX = 14;
int iStartY = 7;

// 목적지 위치
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
				cout << "■";
				break;
			case 0:
				cout << "  ";
				break;
			case 5:
				cout << " S";
				break;
			case 6:
				cout << "▩";
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
	// 현재 위치를 시작지점으로 초기화
	int iPosX = iStartX;
	int iPosY = iStartY;

	for (unsigned int i = 0; i < vecPath.size(); i++)
	{
		int iNextDirection = vecPath[i]; // 다음 위치 저장

		switch (iNextDirection)
		{
		case 0: // 북쪽
			if (((iPosY - 1) < 0) || (iMapArr[iPosY - 1][iPosX] == 1)) // 벽에 닿을 경우, 도착 지점에서 더 움직일 경우
				break;
			else
			{
				iPosY -= 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 1: // 남쪽
			if (((iPosY + 1) >= HEIGHT) || (iMapArr[iPosY + 1][iPosX] == 1))
				break;
			else
			{
				iPosY += 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 2: // 동쪽
			if (((iPosX + 1) >= WIDTH) || (iMapArr[iPosY][iPosX + 1] == 1))
				break;
			else
			{
				iPosX += 1;
				iCopyMap[iPosY][iPosX] = 6;
			}
			break;
		case 3: // 서쪽
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

	return 1 / double(DistanceX + DistanceY + 1); // 적응도 계산 후 반환
}

#endif // !__MAP_INFO_H_