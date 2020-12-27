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
    void run(string inputPath)
    {
        //Extract instructions
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;

            while (getline(newfile, line))
            {
                
            }
        }

	}
};

