#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>
#include <bitset>
#include <queue>

#pragma once
class Day16
{
public:
    class RangeInt
    {
    public: 
        int min;
        int max;

        bool IsInRange(int value)
        {
            return value >= min && value <= max;
        }

        RangeInt()
        {
            min = 0;
            max = 0;
        }

        RangeInt(int min, int max)
        {
            this->min = min;
            this->max = max;
        }
    };

    void run(string inputPath)
    {
        //Vars
        vector<RangeInt> allFieldRanges;

        //Extract nums and put them in a vector
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            bool readingTickets = false;
            while (getline(newfile, line))
            {
                if (Utils::contains_string(line, "nearby tickets:"))
                {
                    readingTickets = true;
                    continue;
                }

                if (!readingTickets)
                {
                    string rightSide = Utils::splitAll(line, ':').at(1);
                    auto ranges = ExtractRanges(rightSide);
                    for (auto range : ranges)
                    {
                        allFieldRanges.push_back(range);
                    }
                }
                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }
    }

    vector<RangeInt> ExtractRanges(string line)
    {
        vector<RangeInt> ranges;
        auto lineSplitted = Utils::splitAll(line, ' ');

        for (auto entry : lineSplitted)
        {
            if (entry == "or")
            {
                continue;
            }

            auto rangeVals = Utils::splitAll(entry, '-');
            ranges.push_back(
                RangeInt(
                    stoi(rangeVals.at(0)),
                    stoi(rangeVals.at(1))
                )
            );
        }
    }
};

