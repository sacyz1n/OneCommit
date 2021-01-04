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
#include "lvl_sol_15.h"
#include "lvl_sol_17.h"
#include "lvl_sol_20.h"
#include "lvl_sol_22.h"
#include "lvl_sol_23.h"
#include "lvl_sol_24.h"
#include "lvl_sol_25.h"
#include "lvl_sol_32.h"
#include "lvl_sol_33.h"
#include "lvl_sol_34.h"
#include "lvl_sol_35.h"

#include "lvl2_sol_1.h"
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
	std::cout << sol_4::solution(3, { 3 }, { 1 }) << std::endl;

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

	// sol 15
	std::cout << sol_15::solution("Zbcdefg") << std::endl;

	std::cout << sol_17::solution(3) << std::endl;

	std::cout << sol_20::solution("z", 10) << std::endl;


	std::cout << sol_22::solution(28) << std::endl;

	std::cout << sol_23::solution("try hello world") << std::endl;

	std::cout << sol_24::solution(123) << std::endl;

	for (int num : sol_25::solution(12345))
		std::cout << num;

	std::cout << sol_32::solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");

	for (int num : sol_33::solution(3, 5))
		std::cout << num;

	std::cout << sol_34::solution(626331) << std::endl;

	std::cout << sol_35::solution(12) << std::endl;

	std::cout << lvl2_sol_1::solution("aabbaccc") << std::endl;
}

