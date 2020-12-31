#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day13
{
public:
    void run(string inputPath)
    {
        //Vars
        long arriveTimestamp = 0;
        vector<long> busses;

        //Extract nums and put them in a vector
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            while (getline(newfile, line))
            {
                if (lineId == 0)
                {
                    arriveTimestamp = stol(line);
                }
                else if (lineId == 1)
                {
                    vector<string> splitLine = Utils::splitAll(line, ',');
                    for (auto bus : splitLine)
                    {
                        if (bus == "x") continue;
                        cout << "bus " << bus << endl;
                        busses.push_back(stol(bus));
                    }
                }
                //cout << lineId << " line " << line << endl;
                //instructions.push_back(NavigationInstruction(line));
                lineId++;
            }
        }

        //Find earliest
        int earliestBus = -1;
        long timestamp = arriveTimestamp - 1;
        while (earliestBus == -1)
        {
            timestamp++;
            for (auto bus : busses)
            {
                if (timestamp % bus == 0)
                {
                    earliestBus = bus;
                    break;
                }
            }
        }
        

        //Show answer
        auto answer = earliestBus * (timestamp - arriveTimestamp);
        cout << "answer is " << answer << endl;


    }
};

