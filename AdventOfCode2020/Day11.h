#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day11
{
public:
    vector<vector<char>> seats;
    int totalRows;
    int totalColumns;
    const char SEAT_FLOOR = '.';
    const char SEAT_EMPTY = 'L';
    const char SEAT_OCCUPPIED = '#';
    vector<pair<int, int>> markedSeatsToChange;

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
                //cout << lineId << " line " << line << endl;
                seats.push_back(vector<char>());
                for (char const& seat : line) 
                {
                    seats.at(lineId).push_back(seat);
                }
                lineId++;
            }
        }
        totalRows = seats.size();
        totalColumns = seats.front().size();

        //Run logic until no seats change
        bool seatsChanged;
        do
        {
            seatsChanged = false;
            markedSeatsToChange.clear();

            //Mark changes
            for (int row = 0; row < totalRows; row++)
            {
                for (int column = 0; column < totalColumns; column++)
                {
                    if (IsSeatFloor(row, column))
                    {
                        continue;
                    }
                    int totalAdjacentOccupied = CountAdjacentOccupied(row, column);
                    
                    if (IsSeatEmpty(row, column) && totalAdjacentOccupied == 0)
                    {
                        markedSeatsToChange.push_back(pair<int,int>(row, column));
                        //seats.at(row).at(column) = SEAT_OCCUPPIED;
                        //seatsChanged = true;
                    }
                    else if (IsSeatOccupied(row, column) && totalAdjacentOccupied >= 4)
                    {
                        markedSeatsToChange.push_back(pair<int, int>(row, column));
                        //seats.at(row).at(column) = SEAT_EMPTY;
                        //seatsChanged = true;
                    }
                }
            }

            //Execute changes
            seatsChanged = markedSeatsToChange.size() > 0;
            for (auto markedSeat : markedSeatsToChange)
            {
                FlipSeat(markedSeat.first, markedSeat.second);
            }

            //DEBUG
            //cout << "\nSeats change " << endl;
            //for (auto seatRow : seats)
            //{
            //    for (auto seat : seatRow)
            //    {
            //        cout << seat;
            //    }
            //    cout << endl;
            //}
        } while (seatsChanged);

        //Show answer
        int totalOccupiedSeat = 0;
        for (auto seatRow : seats)
        {
            for (auto seat : seatRow)
            {
                if (seat == SEAT_OCCUPPIED)
                {
                    totalOccupiedSeat++;
                }
            }
        }

        cout << "totalOccupiedSeat " << totalOccupiedSeat << endl;

	}

    int CountAdjacentOccupied(int row, int column)
    {
        int totalAdjacentOccupied = 0;

        //Brute force
        //Top
        if (IsSeatOccupied(row - 1, column -1))
        {
            totalAdjacentOccupied++;
        }
        if (IsSeatOccupied(row - 1, column))
        {
            totalAdjacentOccupied++;
        }
        if (IsSeatOccupied(row - 1, column + 1))
        {
            totalAdjacentOccupied++;
        }

        //Mid
        if (IsSeatOccupied(row, column - 1))
        {
            totalAdjacentOccupied++;
        }
        if (IsSeatOccupied(row, column + 1))
        {
            totalAdjacentOccupied++;
        }

        //Bot
        if (IsSeatOccupied(row + 1, column - 1))
        {
            totalAdjacentOccupied++;
        }
        if (IsSeatOccupied(row + 1, column))
        {
            totalAdjacentOccupied++;
        }
        if (IsSeatOccupied(row + 1, column + 1))
        {
            totalAdjacentOccupied++;
        }
        

        return totalAdjacentOccupied;
    }

    bool IsSeatOccupied(int row, int column)
    {
        if (row < 0 || row >= totalRows)
        {
            return false;
        }
        if (column < 0 || column >= totalColumns)
        {
            return false;
        }

        return (seats.at(row).at(column) == SEAT_OCCUPPIED);
    }

    bool IsSeatEmpty(int row, int column)
    {
        if (row < 0 || row >= totalRows)
        {
            return false;
        }
        if (column < 0 || column >= totalColumns)
        {
            return false;
        }

        return (seats.at(row).at(column) == SEAT_EMPTY);
    }

    bool IsSeatFloor(int row, int column)
    {
        if (row < 0 || row >= totalRows)
        {
            return false;
        }
        if (column < 0 || column >= totalColumns)
        {
            return false;
        }

        return (seats.at(row).at(column) == SEAT_FLOOR);
    }

    void FlipSeat(int row, int column)
    {
        if (seats.at(row).at(column) == SEAT_OCCUPPIED)
        {
            seats.at(row).at(column) = SEAT_EMPTY;
        }
        else if (seats.at(row).at(column) == SEAT_EMPTY)
        {
            seats.at(row).at(column) = SEAT_OCCUPPIED;
        }
    }
};

