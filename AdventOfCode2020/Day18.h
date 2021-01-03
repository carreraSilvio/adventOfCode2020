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
class Day18
{
public:
    void run(string inputPath)
    {
        //Vars
        stack<string> operationStack;

        //Extract nums 
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;

            while (getline(newfile, line))
            {
                

                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }
    }
};

