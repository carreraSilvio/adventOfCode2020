#include <iostream>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"

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

	cout << "Day 5" << endl;
	Day5 day5;
	day5.run("day5_input.txt");

	return 0;
}

