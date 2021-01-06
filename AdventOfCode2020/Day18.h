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
    class Operation
    {
    public:
        int _left;
        Operation* _right;
        char _operator;

        const char OPERATOR_SUM = '+';
        const char OPERATOR_MULT = '*';

        Operation(int left)
        {
            this->_left = left;
            this->_operator = ' ';
            this->_right = NULL;
        }

        Operation(int left, char _operator, Operation right)
        {
            this->_left = left;
            this->_operator = _operator;
            this->_right = &right;
        }

        int GetResult() 
        {
            if (this->_right == NULL) 
            {
                return _left;
            }
            else
            {
                if (_operator == OPERATOR_SUM)
                {
                    return _left + _right->GetResult();
                }
                else if (_operator == OPERATOR_MULT)
                {
                    return _left * _right->GetResult();
                }
            }
        }
    };
    void run(string inputPath)
    {
        //Vars
        queue<char> tokenQueue;
        int parenthesesDepth;

        //Open file
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (!newfile.is_open())
        {
            cout << "Error opening file" << endl;
        }

        //Extract tokens 
        string line;
        int lineId = 0;
        int sum = 0;

        while (getline(newfile, line))
        {
            sum = 0;
            line = "1 + 2";
            line.erase(line.find_last_not_of(" \n\r\t") + 1);
            for (auto entry : line)
            {
                if (entry == 0)
                {
                    continue;
                }
                tokenQueue.push(entry);
            }
            cout << "result is " << CalculateOperation(tokenQueue) << endl;;
            

            //cout << lineId << " line " << line << endl;
            lineId++;
        }

        //Dummy eg. 1 + 2
        //Dummy eg. 1 + (2 * 3) + (4 * (5 + 6))
        //char left = '2';
        //Operation b = Operation(atoi(&left));
        //left = '1';
        //Operation a = Operation(atoi(&left), '+', b);
        //
        //cout << "result is " << a.GetResult() << endl;;

        
       

    }


    int CalculateOperation(queue<char>& queue)
    {
        if (queue.empty())
        {
            return 0;
        }

        char _left = queue.front();
        queue.pop();
        char _operator = queue.front();
        queue.pop();
        char _right = queue.front();
        queue.pop();

        if (!isdigit(_right))
        {
            return ProcessOperation(_left, _operator, CalculateOperation(queue));
        }

        return ProcessOperation(_left, _operator, _right) + CalculateOperation(queue);
    }

    int ProcessOperation(char _left, char _operator, char _right)
    {
        if (_operator == '+')
        {
            return atoi(&_left) + atoi(&_right);
        }
        else if (_operator == '*')
        {
            return atoi(&_left) * atoi(&_right);
        }
    }
};

