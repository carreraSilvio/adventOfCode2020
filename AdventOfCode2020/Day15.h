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
class Day15
{
public:
    class NumInfo
    {
    public:
        int firstSpoken;
        int secondSpoken;

        NumInfo()
        {
            firstSpoken = -1;
            secondSpoken = -1;
        }

        NumInfo(int lastTurn)
        {
            secondSpoken = lastTurn;
            firstSpoken = -1;
        }

        void Add(int lastTurn)
        {
            firstSpoken = secondSpoken;
            secondSpoken = lastTurn;
        }

        bool WasSpokenTwiceBefore()
        {
            return (firstSpoken != -1 && secondSpoken != -1);
        }

        int CalcTurnDifference()
        {
            return (secondSpoken - firstSpoken);
        }
    };

    void run(string inputPath)
    {
        //Vars
        map<int, NumInfo> spokenLookup; //number, lastTurnSpoken
        queue<int> startingNumbers;
        int mostRecentSpoken;
        int turn = 0;

        //Extract nums and put them in a vector
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            while (getline(newfile, line))
            {
                auto lineSplit = Utils::splitAll(line, ',');
                for (auto num : lineSplit)
                {
                    startingNumbers.push(stoi(num));
                }
                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }

        //Run input numbers
        int totalStartingNumbers = startingNumbers.size();
        while (turn < totalStartingNumbers)
        {
            int nextNum = startingNumbers.front();
            mostRecentSpoken = nextNum;
            spokenLookup.insert(pair<int, NumInfo>(nextNum, NumInfo(turn)));
            startingNumbers.pop();
            turn++;
        }


        //Run until 2020th turn
        while (turn < 2020)
        {
            if (!spokenLookup.at(mostRecentSpoken).WasSpokenTwiceBefore())
            {
                if (spokenLookup.find(0) != spokenLookup.end())
                {
                    spokenLookup.at(0).Add(turn);
                }
                else
                {
                    spokenLookup.insert(pair<int, NumInfo>(0, NumInfo(turn)));
                }
                mostRecentSpoken = 0;
            }
            else
            {
                int turnDifference = spokenLookup.at(mostRecentSpoken).CalcTurnDifference();
                mostRecentSpoken = turnDifference;
                if (spokenLookup.find(mostRecentSpoken) != spokenLookup.end())
                {
                    spokenLookup.at(mostRecentSpoken).Add(turn);
                }
                else
                {
                    spokenLookup.insert(pair<int, NumInfo>(mostRecentSpoken, NumInfo(turn)));
                }
            }
            cout << "turn " << turn + 1 << " mostRecent " << mostRecentSpoken << endl;
            turn++;
            
        }

        //Print answer
        cout << "2020th number is " << mostRecentSpoken << endl;
    }
};

