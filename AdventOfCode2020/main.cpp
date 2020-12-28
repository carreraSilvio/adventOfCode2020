#include <iostream>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"

using namespace std;

int main()
{
	cout.setf(std::ios::boolalpha);

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

	cout << "Day 9" << endl;
	Day9 day9;
	//day9.run("day9_input_dummy.txt", 5);
	day9.run("day9_input.txt", 25);

	return 0;
}

