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
class Day17
{
public:
    class Coord
    {
    public:
        int x;
        int y;
        int z;
        Coord()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }
        Coord(int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        bool operator<(const Coord& r) const 
        {
            return (
                x < r.x || 
                x == r.x && y < r.y  ||
                x == r.x && y == r.y && z < r.z);
        }

        bool operator>(const Coord& r) const
        {
            return (
                x > r.x ||
                x == r.x && y > r.y ||
                x == r.x && y == r.y && z > r.z);
        }

        bool operator==(const Coord& r) const
        {
            return (x == r.x && y == r.y && z == r.z);
        }

        
    };

    void run(string inputPath)
    {
        //Consts

        //Vars
        map<Coord, bool> matrix;

        //create a matrix space of 20x20
        for (int x = -10; x < 10; x++)
            for (int y = -10; y < 10; y++)
                for (int z = -10; z < 10; z++)
                    matrix.insert(pair<Coord, bool>(Coord(x,y,z), false));

        //Extract nums 
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            Coord inputCord;

            while (getline(newfile, line))
            {
                vector<string> lineSplit = Utils::splitAll(line, ',');
                inputCord.x = 0;
                for (auto entry : lineSplit)
                {
                    bool isActive = (entry == "#");
                    matrix.at(inputCord) = isActive;
                    inputCord.x++; 
                }
                inputCord.y++;

                
                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }
    }
};

