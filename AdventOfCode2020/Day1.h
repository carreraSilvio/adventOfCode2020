#include <iostream>// std::cout
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // std::binary_search, std::sort
#include "Utils.h"

using namespace std;

#pragma once
class Day1
{
public:
	int run()
	{
		int targetSum = 2020;

		//Read input data
		vector<int> nums;
		fstream newfile;
		newfile.open("day1_input.txt", ios::in);
		if (newfile.is_open())
		{
			string line;
			while (getline(newfile, line))
			{
				nums.push_back(stoi(line));
				//cout << line << "\n";
			}
			newfile.close();
		}

		//Sort list
		sort(nums.begin(), nums.end());
		//cout << "ascending:  " << nums << "\n";

		//Do binary search
		int upperIndex = nums.size() - 1;

		while (upperIndex > -1)
		{
			int upperValue = nums[upperIndex];
			if (upperValue >= targetSum) {
				upperIndex--;
				continue;
			}

			int targetLowerValue = targetSum - upperValue;
			if (!binary_search(nums.begin(), nums.end(), targetLowerValue)) {
				upperIndex--;
				continue;
			}

			//Found valid numbers
			//cout << "upperValue " << upperValue << " targetLowerValue " << targetLowerValue << endl;
			cout << "res " << upperValue * targetLowerValue << endl;
			return upperValue * targetLowerValue;
		}

		cout << "res " << "not found.\n";
		return 0;
	}
};

