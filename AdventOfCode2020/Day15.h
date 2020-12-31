#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>
#include <bitset>

#pragma once
class Day15
{
public:
    void run(string inputPath)
    {
        //Vars

        //Extract nums and put them in a vector
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

