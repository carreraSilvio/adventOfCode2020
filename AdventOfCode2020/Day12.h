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
    
    class Ship
    {
    public:
        string facing;
        int x;
        int y;

         const string FACING_NORTH = "N";
         const string FACING_SOUTH = "S";
         const string FACING_EAST = "E";
         const string FACING_WEST = "W";

        Ship() 
        {
            facing = FACING_EAST;
            x = 0;
            y = 0;
        }
    };

    class NavigationInstruction
    {
    public:
        string action = "";
        int argument = 0;

        const string ACTION_MOVE_FORWARD = "F";

        const string ACTION_MOVE_NORTH = "N";
        const string ACTION_MOVE_SOUTH = "S";
        const string ACTION_MOVE_EAST = "E";
        const string ACTION_MOVE_WEST = "W";

        const string ACTION_TURN_RIGHT = "R";
        const string ACTION_TURN_LEFT = "L";

        NavigationInstruction(string inputData)
        {
            action = inputData.substr(0, 1);
            argument = stoi(inputData.substr(1, inputData.size() - 1));
            //cout << "action " << action << endl;
            //cout << "argument " << argument << endl;
        }

        void ExecuteAction(Ship& ship)
        {
            if (action == ACTION_MOVE_FORWARD)
            {
                if (ship.facing == ship.FACING_NORTH)
                {
                    MoveNorth(ship);
                }
                else if (ship.facing == ship.FACING_EAST)
                {
                    MoveEast(ship);
                }
                else if (ship.facing == ship.FACING_WEST)
                {
                    MoveWest(ship);
                }
                else if (ship.facing == ship.FACING_SOUTH)
                {
                    MoveSouth(ship);
                }
            }
            else if (action == ACTION_MOVE_NORTH)
            {
                MoveNorth(ship);
            }
            else if (action == ACTION_MOVE_SOUTH)
            {
                MoveSouth(ship);
            }
            else if (action == ACTION_MOVE_EAST)
            {
                MoveEast(ship);
            }
            else if (action == ACTION_MOVE_WEST)
            {
                MoveWest(ship);
            }
            else if (action == ACTION_TURN_LEFT)
            {
                int turnAmount = argument / 90;
                while (turnAmount > 0)
                {
                    TurnLeft(ship);
                    turnAmount -= 1;
                }
            }
            else if (action == ACTION_TURN_RIGHT)
            {
                int turnAmount = argument / 90;
                while (turnAmount > 0)
                {
                    TurnRight(ship);
                    turnAmount -= 1;
                }
            }
            
        }

        void MoveEast(Day12::Ship& ship)
        {
            ship.x += argument;
        }

        void MoveWest(Day12::Ship& ship)
        {
            ship.x -= argument;
        }

        void MoveNorth(Day12::Ship& ship)
        {
            ship.y += argument;
        }

        void MoveSouth(Day12::Ship& ship)
        {
            ship.y -= argument;
        }

        void TurnLeft(Ship& ship)
        {
            if (ship.facing == ship.FACING_NORTH)
            {
                ship.facing = ship.FACING_WEST;
            }
            else if (ship.facing == ship.FACING_WEST)
            {
                ship.facing = ship.FACING_SOUTH;
            }
            else if (ship.facing == ship.FACING_SOUTH)
            {
                ship.facing = ship.FACING_EAST;
            }
            else if (ship.facing == ship.FACING_EAST)
            {
                ship.facing = ship.FACING_NORTH;
            }
        }

        void TurnRight(Ship& ship)
        {
            if (ship.facing == ship.FACING_NORTH)
            {
                ship.facing = ship.FACING_EAST;
            }
            else if (ship.facing == ship.FACING_EAST)
            {
                ship.facing = ship.FACING_SOUTH;
            }
            else if (ship.facing == ship.FACING_SOUTH)
            {
                ship.facing = ship.FACING_WEST;
            }
            else if (ship.facing == ship.FACING_WEST)
            {
                ship.facing = ship.FACING_NORTH;
            }
        }

    };

    Ship ship;
    vector<NavigationInstruction> instructions;

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
                instructions.push_back(NavigationInstruction(line));
                lineId++;
            }
        }

        //Execute navigation instructions
        for (auto instruction : instructions)
        {
            instruction.ExecuteAction(ship);
            //cout << "#executed " << instruction.action << " " << instruction.argument << endl;
            //cout << "facing " << ship.facing <<" x " << ship.x << " y " << ship.y << endl;
        }

        //Calculate answer
        int manhattanDistance = abs(ship.x) + abs(ship.y);

        //Show answer
        cout << "manhattanDistance " << manhattanDistance << endl;

    }
};

