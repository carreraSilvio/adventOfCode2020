#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day10
{
public:
	void run(string inputPath)
    {
        //vars
        vector<int> nums;
        int oneJoltDifTotal = 0;
        int threeJoltDifTotal = 0;

        //Add wall outlet
        int wallOutlet = 0;
        nums.push_back(wallOutlet);

        //Extract nums and put them in an array
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            while (getline(newfile, line))
            {
                //cout << lineId++ << " line " << line << endl;
                nums.push_back(stoi(line));
            }
        }

        //Order array
        sort(nums.begin(), nums.end());

        //Add highest rating adapter
        int highestRatingAdapter = nums.back() + 3;
        nums.push_back(highestRatingAdapter);

        //Count diferences
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int dif = nums.at(i + 1) - nums.at(i);
            //cout << "dif " << dif << " => "<< nums.at(i + 1)  << "-" << nums.at(i) << endl;
            if (dif == 1)
            {
                oneJoltDifTotal++;
            }
            else if (dif == 3)
            {
                threeJoltDifTotal++;
            }
        }

        cout << "oneJoltDifTotal " << oneJoltDifTotal << " threeJoltDifTotal " << threeJoltDifTotal << endl;
        cout << "resp => " << oneJoltDifTotal * threeJoltDifTotal << endl;
	}
};

