// algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "lvl_sol_1.h"
int main()
{
	for (auto number : sol_1::solution({ 1,2,3,4,5,6,7 }))
		std::cout << number << std::endl;
}

