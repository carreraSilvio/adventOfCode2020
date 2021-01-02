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
        //consts
        const int STATE_RANGES = 0;
        const int STATE_USER_TICKET = 1;
        const int STATE_NEARBY_TICKET = 2;

        //Vars
        vector<RangeInt> allFieldRanges;
        vector<vector<int>> nearbyTickets;
        int state = STATE_RANGES;

        //Extract nums and put them in a vector
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            while (getline(newfile, line))
            {
                if (line.empty())
                {
                    continue;
                }

                if (Utils::contains_string(line, "nearby tickets:"))
                {
                    state = STATE_NEARBY_TICKET;
                    continue;
                }

                if (Utils::contains_string(line, "your ticket:"))
                {
                    state = STATE_NEARBY_TICKET;
                    continue;
                }

                if (state == STATE_RANGES)
                {
                    string rightSide = Utils::splitAll(line, ':').at(1);
                    auto ranges = ExtractRanges(rightSide);
                    for (auto range : ranges)
                    {
                        allFieldRanges.push_back(range);
                    }
                }
                else if (state == STATE_USER_TICKET)
                {
                    //NA continue
                }
                else if (state == STATE_NEARBY_TICKET)
                {
                    vector<string> lineSplit = Utils::splitAll(line, ',');
                    vector<int> nearbyTicket;
                    for (auto num : lineSplit)
                    {
                        nearbyTicket.push_back(stoi(num));
                    }
                    nearbyTickets.push_back(nearbyTicket);
                }

                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }

        //Sum invalid values
        unsigned long long sum = 0;
        bool invalid = true;
        for (auto nearbyTicket : nearbyTickets)
        {
            for (auto value : nearbyTicket)
            {
                invalid = true;
                for (auto range : allFieldRanges)
                {
                    if (range.IsInRange(value))
                    {
                        invalid = false;
                        break;
                    }
                }

                if (invalid)
                {
                    sum += value;
                }
            }
        }

        //Show answer
        cout << "resp is " << sum << endl;
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
            if (entry.empty())
            {
                continue;
            }

            auto rangeVals = Utils::splitAll(entry, '-');
            auto min = stoi(rangeVals.at(0));
            auto max = stoi(rangeVals.at(1));
            ranges.push_back(RangeInt(min,max));
        }

        return ranges;
    }
};

