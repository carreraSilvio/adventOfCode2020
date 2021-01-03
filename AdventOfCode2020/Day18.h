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
        stack<char> stack;
        int parenthesesDepth;

        //Extract nums 
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            int sum = 0;

            while (getline(newfile, line))
            {
                sum = 0;
                for (auto entry : line)
                {
                    if (entry != '(' && entry != ')' && entry != '*' && entry != '+')
                    {
                        sum = //  2 + (1 + (3+1) + 2)
                            /// stack #1
                            /// 2 
                            /// +
                            ///  (
                            ///  1 
                            ///  + 
                            ///   (
                            ///   3
                            ///   +
                            ///   1
                            ///   *
                            ///   5
                            ///   )
                            ///  +
                            ///  2
                            ///  )
                            /// stack #2
                            /// 2 
                            /// +
                            /// (
                            /// 1 
                            /// + 
                            /// (
                            /// 3
                            /// +
                            /// 1
                            /// )
                            /// +
                            /// 2
                    }

                }

                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }
    }
};

