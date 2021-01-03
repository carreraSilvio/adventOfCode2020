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

        bool IsNeighbor(int x, int y, int z)
        {
            return (
                abs(this->x - x) == 1 ||
                abs(this->y - y) == 1 ||
                abs(this->z - z) == 1
                );
        }

        bool IsNeighbor(Coord coord)
        {
            return IsNeighbor(coord.x, coord.y, coord.z);
        }
        
    };

    map<Coord, bool> matrix;
    const int MATRIX_SIZE = 40;
    const int TOTAL_CYCLES = 6;

    void run(string inputPath)
    {
        //Vars
        vector<Coord> markedToChange;

        //create a matrix space of size x size
        for (int x = 0; x < MATRIX_SIZE; x++)
            for (int y = 0; y < MATRIX_SIZE; y++)
                for (int z = 0; z < MATRIX_SIZE; z++)
                    matrix.insert(pair<Coord, bool>(Coord(x,y,z), false));

        //Extract nums 
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            int lineId = 0;
            Coord inputCord;
            inputCord.z = (MATRIX_SIZE / 2) - 1;
            inputCord.y = (MATRIX_SIZE / 2) - 1;

            while (getline(newfile, line))
            {
                inputCord.x = (MATRIX_SIZE / 2) - 1;
                for (auto entry : line)
                {
                    bool isActive = (entry == '#');
                    matrix.at(inputCord) = isActive;

                    inputCord.x++; 
                }
                inputCord.y++;
                
                //cout << lineId << " line " << line << endl;
                lineId++;
            }
        }

        //Run cycles
        int cycle = 1;
        
        while (cycle <= TOTAL_CYCLES)
        {
            cout << "Cycle " << cycle << endl;

            //Mark all that will change
            cout << "#Mark to change " << endl;
            markedToChange.clear();
            for (const auto& cube : matrix)
            {
                Coord coord = cube.first;
                bool active = cube.second;
                int totalNeighborsActive = CountNeighborsActive(coord);
                if (active && (totalNeighborsActive < 2 || totalNeighborsActive > 3))
                {
                    markedToChange.push_back(coord);
                }
                else if (!active && totalNeighborsActive == 3)
                {
                    markedToChange.push_back(coord);
                }
            }

            //Apply changes
            cout << "#Apply changes" << endl;
            for (const auto& coord : markedToChange)
            {
                matrix.at(coord) = !matrix.at(coord); //flip the value

                bool isActive = matrix.at(coord);
            }

            //PrintMatrix();
            cycle++;
        }

        //Count active cubes
        int totalActiveCubes = 0;
        for (int z = 0; z < MATRIX_SIZE; z++)
        {
            for (int y = 0; y < MATRIX_SIZE; y++)
            {
                for (int x = 0; x < MATRIX_SIZE; x++)
                {
                    if (matrix.at(Coord(x, y, z)))
                    {
                        totalActiveCubes++;
                    }
                }
            }
        }

        //Show answer
        cout << "total active cubes is " << totalActiveCubes << endl;

    }

    void PrintMatrix()
    {
        for (int z = 0; z < MATRIX_SIZE; z++)
        {
            cout << "z = " << z << endl;
            for (int y = 0; y < MATRIX_SIZE; y++)
            {
                for (int x = 0; x < MATRIX_SIZE; x++)
                {
                    cout << (matrix.at(Coord(x, y, z)) == true ? "#" : ".");
                }
                cout << endl;
            }
        }
    }

    int CountNeighborsActive(Coord middleCoord)
    {
        int totalActive = 0;

        //Check on Z -1, 0 and +1
        for (int z = middleCoord.z - 1; z < middleCoord.z + 2; z++)
        {
            for (int y = middleCoord.y - 1; y < middleCoord.y + 2; y++)
            {
                for (int x = middleCoord.x - 1; x < middleCoord.x + 2; x++)
                {
                    if (x == -1 || y == -1 || z == -1)
                    {
                        continue;
                    }

                    if (x == MATRIX_SIZE || y == MATRIX_SIZE || z == MATRIX_SIZE)
                    {
                        continue;
                    }

                    auto coord = Coord(x, y, z);
                    if (coord == middleCoord) //Ignore self
                    {
                        continue;
                    }

                    if (matrix.at(coord)) //Is active?
                    {
                        totalActive++;
                    }


                    //cout << (matrix.at(Coord(x, y, z)) == true ? "#" : ".");
                }
                //cout << endl;
            }
        }
        return totalActive;
    }
};

