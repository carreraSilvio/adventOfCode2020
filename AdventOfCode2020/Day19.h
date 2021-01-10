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
#include <stack>

#pragma once
class Day19
{
public:

    void run(string inputPath)
    {
        //Vars
        map<int, string> rules;
        vector<string> messages;

        //Open file
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (!newfile.is_open())
        {
            cout << "Error opening file" << endl;
        }

        //Extract rules and messages 
        string line;
        int lineId = 0;
        bool extractingRules = true;
        

        while (getline(newfile, line))
        {
            if (line == " ")
            {
                extractingRules = false;
                continue;
            }

            for (auto entry : line)
            {
                if (extractingRules)
                {
                    auto lineSplit = Utils::divide(line, ':');
                    rules.insert(pair<int, string>(stoi(lineSplit.at(0)), lineSplit.at(1)));
                }
            }
            //cout << lineId << " line " << line << endl;
            lineId++;
        }

        //Sum all result
        cout << "resultSum is " << resultSum << endl;

    }
};