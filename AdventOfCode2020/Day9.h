#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day9
{
public:
    typedef long long bigNum;

    vector<bigNum>nums;
    vector<bigNum>lookupNums;
    int lookupMinIndex = 0;
    int lookupMaxIndex = 0;
    int targetIndex = 0;
    int target = 0;
    int preamble = 0;

    void run(string inputPath, int preamble)
    {
        //vars
        this->preamble = preamble;

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
                auto dataNum = std::stoll(line);
                nums.push_back(dataNum);
            }
        }

        //Navigate the array searching for a number where you can't find 
        //a pair that sums up to in it's premalbe nths number 
        //Eg. premable = 5; num in id 5 should equal sum of a pair between 0 and 4
        lookupMinIndex = 0;
        lookupMaxIndex = preamble - 1;
        targetIndex = preamble;

        while (targetIndex < nums.size()) 
        {
            target = nums.at(targetIndex);
            UpdateLookupVector();
            if (!DoBinarySearch())
            {
                cout << "target " << target << " has no valid sum" << endl;
                return;
            }
            lookupMinIndex++;
            lookupMaxIndex++;
            targetIndex++;
        }

        cout << "all are valid " << endl;
	}

    void UpdateLookupVector() 
    {
        lookupNums.clear();
        for (int aux = lookupMinIndex; aux <= lookupMaxIndex; aux++)
        {
            lookupNums.push_back(nums.at(aux));
        }
    }

    bool DoBinarySearch()
    {
        sort(lookupNums.begin(), lookupNums.end());
        //cout << "ascending:  " << nums << "\n";   

        int upperIndex = lookupNums.size() - 1;
        while (upperIndex > -1)
        {
            int upperValue = lookupNums[upperIndex];
            if (upperValue >= target) {
                upperIndex--;
                continue;
            }

            int targetLowerValue = target - upperValue;
            if (!binary_search(lookupNums.begin(), lookupNums.end(), targetLowerValue)) {
                upperIndex--;
                continue;
            }

            //Found valid numbers
            //cout << "target " << target << " upperValue " << upperValue << " targetLowerValue " << targetLowerValue << endl;
            return true;
        }
        return false;
    }
};

