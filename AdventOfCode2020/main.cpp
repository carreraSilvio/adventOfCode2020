#include <iostream>
#include <chrono>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"
#include "Day13.h"
#include "Day14.h"
#include "Day15.h"
#include "Day16.h"
#include "Day17.h"
#include "Day18.h"
#include "Day19.h"

using namespace std;

int main()
{
	cout.setf(std::ios::boolalpha);
	chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	//cout << "Day 1" << endl;
	//Day1 day1;
	//day1.run();

	//cout << "Day 2" << endl;
	//Day2 day2;
	//day2.run("day2_input.txt");

	//cout << "Day 3" << endl;
	//Day3 day3;
	//day3.run("day3_input.txt");

	//cout << "Day 4" << endl;
	//Day4 day4;
	//day4.run("day4_input.txt");

	//cout << "Day 5" << endl;
	//Day5 day5;
	//day5.run("day5_input.txt");

	//cout << "Day 6" << endl;
	//Day6 day6;
	//day6.run("day6_input.txt");

	//cout << "Day 7" << endl;
	//Day7 day7;
	//day7.run("day7_input.txt");

	//cout << "Day 8" << endl;
	//Day8 day8;
	////day8.run("day8_input_dummy.txt");
	//day8.run("day8_input.txt");

	//cout << "Day 9" << endl;
	//Day9 day9;
	//day9.run("day9_input_dummy.txt", 5);
	//day9.run("day9_input.txt", 25);

	//cout << "Day 10" << endl;
	//Day10 day10;
	//day10.run("day10_input_dummy.txt");
	//day10.run("day10_input.txt");

	//cout << "Day 11" << endl;
	//Day11 day11;
	//day11.run("day11_input_dummy.txt");
	//day11.run("day11_input.txt");

	//cout << "Day 12" << endl;
	//Day12 day12;
	//day12.run("day12_input_dummy.txt");
	//day12.run("day12_input.txt");

	//cout << "Day 13" << endl;
	//Day13 day13;
	//day13.run("day13_input_dummy.txt");
	//day13.run("day13_input.txt");

	//cout << "Day 14" << endl;
	//Day14 day14;
	//day14.run("day14_input_dummy.txt");
	//day14.run("day14_input.txt");

	//cout << "Day 15" << endl;
	//Day15 day15;
	//day15.run("day15_input_dummy.txt");
	//day15.run("day15_input.txt");

	//cout << "Day 16" << endl;
	//Day16 day16;
	//day16.run("day16_input_dummy.txt");
	//day16.run("day16_input.txt");

	//cout << "Day 17" << endl;
	//Day17 day17;
	//day17.run("day17_input_dummy.txt"); 
	//day17.run("day17_input.txt");

	//cout << "Day 18" << endl;
	//Day18 day18;
	//day18.run("day18_input_dummy.txt"); 
	//day18.run("day18_input.txt");

	cout << "Day 19" << endl;
	Day19 day19;
	day19.run("day19_input_dummy.txt"); 
	//day19.run("day19_input.txt");

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Time taken = " << chrono::duration_cast<chrono::milliseconds> (end - begin).count() << "[ms]" << endl;

	return 0;
}