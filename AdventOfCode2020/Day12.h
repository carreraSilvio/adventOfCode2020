#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day12
{
public:
    string facing;
    const string FACING_INITIAL = "E";
    const string FACING_NORTH = "N";
    const string FACING_SOUTH = "S";
    const string FACING_EAST = "E";
    const string FACING_WEST = "W";

    const string ACTION_FACE_NORTH = "N";
    const string ACTION_FACE_SOUTH = "S";
    const string ACTION_FACE_EAST = "E";
    const string ACTION_FACE_WEST = "W";
    const string ACTION_TURN_RIGHT = "R";
    const string ACTION_TURN_LEFT = "L";

    void run(string inputPath)
    {
        //Extract nums and put them in a vector
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            while (getline(newfile, line))
            {
                auto t = NavigationInstruction(line);
                //cout << lineId << " line " << line << endl;
                //seats.push_back(vector<char>());
                //for (char const& seat : line)
                //{
                    //seats.at(lineId).push_back(seat);
                //}
                lineId++;
            }
        }
    }

    class NavigationInstruction
    {
    public:
        string action = "";
        int argument = 0;

        NavigationInstruction(string inputData)
        {
            action = inputData.substr(0, 1);
            argument = stoi(inputData.substr(1, inputData.size() - 1));
            cout << "action " << action << endl;
            cout << "argument " << argument << endl;
        }

    };
};

