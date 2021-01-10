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
        queue<char> tokenQueue;
        long long resultSum = 0;

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
            for (auto entry : line)
            {
                if (entry == ' ')
                {
                    continue;
                }
                tokenQueue.push(entry);
            }
            auto result = CalculateExpression(tokenQueue);
            resultSum += result;
            cout << "result is " << result << endl;

            //cout << lineId << " line " << line << endl;
            lineId++;
        }

        //Sum all result
        cout << "resultSum is " << resultSum << endl;

    }

    int FetchPrecedence(char c)
    {
        if (c == '+' || c == '*')
        {
            return 1;
        }

        return 0;
    }

    long long CalculateExpression(queue<char>& expression)
    {
        vector<char> postfixNotation;
        stack<char> postfixStack ;

        while(!expression.empty())
        {
            auto c = expression.front();
            expression.pop();

            if (isdigit(c))
            {
                postfixNotation.push_back(c);
            }
            else if (c == '(')
            {
                postfixStack.push(c);
            }
            else if (c == ')')
            {
                while (postfixStack.size() > 0 && postfixStack.top() != '(')
                {
                    postfixNotation.push_back(postfixStack.top());
                    postfixStack.pop();
                }

                if (postfixStack.size() > 0)
                {
                    postfixStack.pop();
                }
            }
            else
            {
                while (postfixStack.size() > 0 && FetchPrecedence(c) <= FetchPrecedence(postfixStack.top()))
                {
                    postfixNotation.push_back(postfixStack.top());
                    postfixStack.pop();
                }

                postfixStack.push(c);
            }
        }

        while (postfixStack.size() > 0)
        {
            postfixNotation.push_back(postfixStack.top());
            postfixStack.pop();
        }

        stack<long long> expressionStack;

        for(char c : postfixNotation)
        {
            if (isdigit(c))
            {
                expressionStack.push(atoll(&c));
            }
            else
            {
                long long a = expressionStack.top();
                expressionStack.pop();
                long long b = expressionStack.top();
                expressionStack.pop();

                if (c == '+')
                {
                    expressionStack.push(a + b);
                }
                else if (c == '*')
                {
                    expressionStack.push(a * b);
                }
            }
        }

        return expressionStack.top();
    }
  
};

