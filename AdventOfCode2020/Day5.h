#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#pragma once
class Day5
{
public:
    void run(string inputPath) {

        //Define vars
        vector<BoardingPass> boardingPasses;

        //Read input, parse and calc solution
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            while (getline(newfile, line))
            {
                //Inject each line in a bording pass
                cout << "line " << line << "\n";
                boardingPasses.push_back(BoardingPass(line));
            }
            newfile.close();
        }

        //Fetch highest id
        int highestId = 0;

        for (auto boardingPass : boardingPasses) 
        {
            if (boardingPass.id > highestId) 
            {
                highestId = boardingPass.id;
            }
        }


        cout << "Highest id is " << highestId << endl;
    }

    class BoardingPass {
    public:
        int row = 0;
        int column = 0;
        int id = 0;

        const int PLANE_LAST_ROW_INDEX = 127;
        const int PLANE_LAST_COL_INDEX = 7;

        const char PLANE_ROW_F = 'F';;// means "front" 
        const char PLANE_ROW_B = 'B';// means "back"
        const char PLANE_COL_L = 'L';// means "left"
        const char PLANE_COL_R = 'R';// means "right"

        //eg. FBFBBFFRLR
        BoardingPass(string fullValue) 
        {
            //Split FBFBBFFRLR into FBFBBFF (row calc) and RLR(col calc)
            auto rowData = fullValue.substr(0, 7);
            auto columnData = fullValue.substr(7, fullValue.length());

            //Calculate row
            int rowMin = 0;
            int rowMax = PLANE_LAST_ROW_INDEX;
            for (int rowDataIndex = 0; rowDataIndex < rowData.length(); rowDataIndex++) 
            {
                auto entry = rowData[rowDataIndex];
                //cout << entry << " row range is [" << rowMin << "," << rowMax << "]" << endl;

                if (rowDataIndex == rowData.length() - 1)
                {
                    if (entry == PLANE_ROW_F)
                    {
                        row = rowMin;
                    }
                    else if (entry == PLANE_ROW_B)
                    {
                        row = rowMax;
                    }
                }
                else 
                {
                    if (entry == PLANE_ROW_F) 
                    {
                        rowMax = rowMax - std::floor((rowMax - rowMin) / 2) - 1;
                    }
                    else if (entry == PLANE_ROW_B) 
                    {
                        rowMin = rowMin +  std::floor((rowMax - rowMin) / 2) + 1;
                    }
                }
            }

            //Calculate column
            int columnMin = 0;
            int columnMax = PLANE_LAST_COL_INDEX;
            for (int colDataIndex = 0; colDataIndex < columnData.length(); colDataIndex++)
            {
                auto entry = columnData[colDataIndex];
                //cout << entry << " column range is [" << columnMin << "," << columnMax << "]" << endl;

                if (colDataIndex == columnData.length() - 1)
                {
                    if (entry == PLANE_COL_L)
                    {
                        column = columnMin;
                    }
                    else if (entry == PLANE_COL_R)
                    {
                        column = columnMax;
                    }
                }
                else
                {
                    if (entry == PLANE_COL_L)
                    {
                        columnMax = columnMax - std::floor((columnMax - columnMin) / 2) - 1;
                    }
                    else if (entry == PLANE_COL_R)
                    {
                        columnMin = columnMin + std::floor((columnMax - columnMin) / 2) + 1;
                    }
                }

               
            }

            //Calculate id
            id = (row * 8) + column;

            //cout << "row is " << row << endl;
            //cout << "col is " << column << endl;
            //cout << "id is " << id << endl;
        }
    };
};

