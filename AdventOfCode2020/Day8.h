#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day8
{
public:
    class Instruction {
    public:
        string operation;
        int argument;

        const string OPERATION_ACC = "acc";
        const string OPERATION_JMP = "jmp";
        const string OPERATION_NOP = "nop";

        Instruction(string rawData)
        {
            vector<string> lineSplit = Utils::divide(rawData, ' ');
            string leftSide = lineSplit[0];
            string rightSide = lineSplit[1];

            operation = leftSide;
            argument = stoi(rightSide);
        }

        void Execute(int& accumulator, int& nextInstruction)
        {
            if (operation == OPERATION_JMP)
            {
                nextInstruction += argument;
            }
            else if (operation == OPERATION_ACC)
            {
                accumulator += argument;
                nextInstruction += 1;
            }
            else if (operation == OPERATION_NOP)
            {
                nextInstruction += 1;
            }
        }
    };

    vector<Instruction> instructions = vector<Instruction>();
    vector<int> instructionsExecuted = vector<int>();
    int accumulator = 0;

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
                instructions.push_back(Instruction(line));
            }
        }

        //Execute instructions
        int nextInstruction = 0;
        while(nextInstruction < instructions.size())
        {
            if (!instructionsExecuted.empty() && 
                find(instructionsExecuted.begin(), instructionsExecuted.end(), nextInstruction) != instructionsExecuted.end())
            {
                cout << "Instruction " << nextInstruction << " already executed. Aborting." << endl;
                break;
            }
            instructionsExecuted.push_back(nextInstruction);

            try
            {
                auto instruction = instructions.at(nextInstruction);
                instruction.Execute(accumulator, nextInstruction);
                cout << "Execute " << instruction.operation << " " << instruction.argument << endl;
            }
            catch(exception e)
            {
                cout << "Invalid instruction " << nextInstruction << " index. Aborting." << endl;
                break;
            }
        }

        //Display result
        cout << "accumulator is " << accumulator << endl;

	}
};

