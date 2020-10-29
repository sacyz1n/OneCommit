// algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "lvl_sol_1.h"
#include "lvl_sol_2.h"
#include "lvl_sol_3.h"
#include "lvl_sol_4.h"
int main()
{
	//for (auto number : sol_1::solution({ 1,2,3,4,5,6,7 }))
	//	std::cout << number << std::endl;

	for (auto number : sol_2::solution({ 1, 5, 2, 6, 3, 7, 4 }, { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } }))
		std::cout << number << std::endl;

	// sol 3
	std::cout << sol_3::solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << std::endl;

	// sol 4
	//std::cout << sol_4::solution(5, { 2, 4 }, { 1, 3, 5 }) << std::endl;
	std::cout << sol_4::solution(3, { 3 }, { 1}) << std::endl;
}

