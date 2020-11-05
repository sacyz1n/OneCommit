// algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "lvl_sol_1.h"
#include "lvl_sol_2.h"
#include "lvl_sol_3.h"
#include "lvl_sol_4.h"
#include "lvl_sol_5.h"
#include "lvl_sol_6.h"
#include "lvl_sol_7.h"
#include "lvl_sol_8.h"
#include "lvl_sol_9.h"
#include "lvl_sol_10.h"
#include "lvl_sol_11.h"
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

	// sol 5
	std::cout << sol_5::solution(5, 24) << std::endl;

	// sol 6
	std::cout << sol_6::solution("abcde") << std::endl;
	std::cout << sol_6::solution("abde") << std::endl;

	// sol 7
	std::cout << sol_7::solution(1) << std::endl;

	// sol 8
	for (auto number : sol_8::solution({ 1, 1, 3, 3, 0, 1, 1 }))
		std::cout << number;

	// sol 9
	for (auto number : sol_9::solution({ 5, 9, 7, 10 }, 5))
		std::cout << number;

	// sol 11
	for (auto& str : sol_11::solution({ "abce", "abcd", "cdx" }, 2))
	//for (auto& str : sol_11::solution({ "sun", "bed", "car" }, 1))
		std::cout << str << std::endl;
}

