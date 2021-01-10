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
class Day19
{
public:

    class Node
    {
    public:
        vector<string> subNodes;
        Node(vector<string> values) {
            for (auto value : values)
            {
                subNodes.push_back(value);
            }
        }
    };

    void run(string inputPath)
    {
        //Vars
        map<int, Node> rules;
        vector<string> messages;
        vector<string> validMessages;
        string ruleZero = " ";

        //Open file
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (!newfile.is_open())
        {
            cout << "Error opening file" << endl;
        }

        //Extract rules and messages 
        string line;
        int lineId = 0;
        bool extractingRules = true;

        while (getline(newfile, line))
        {
            if (line == " ")
            {
                extractingRules = false;
                continue;
            }
            
            if (extractingRules)
            {
                auto lineSplit = Utils::divide(line, ':');

                if (ruleZero == " ")
                {
                    ruleZero = lineSplit.at(1);
                }
                else
                {
                    auto key = stoi(lineSplit.at(0));
                    auto values = lineSplit.at(1);
                    auto valuesSplit = Utils::splitAll(values, ':');
                    Node node = Node(valuesSplit);
                    
                
                    rules.insert(pair<int, Node>(key, node);
                }
            }
            else
            {
                messages.push_back(line);
            }
            
            //cout << lineId << " line " << line << endl;
            lineId++;
        }

        //Find all valid messages for rule 0
        while (true)
        {
            string validMessage = " ";
            for (auto entry : ruleZero)
            {
                if (entry == ' ')
                {
                    continue;
                }

                if (entry == 'a' || entry == 'b')
                {
                    validMessage.push_back(entry);
                    continue;
                }
            }
            validMessages.push_back(validMessage);
        };
        

        //Count all messages that match the valid messages
        int rightMessages = 0;

        for (auto message : messages)
        {
            for (auto validMessage : validMessages)
            {
                if (message.length() != validMessage.length())
                {
                    continue;
                }

                if (message.compare(validMessage))
                {
                    rightMessages++;
                    break;
                }
            }
        }

        //Show result
        cout << "rightMessages is " << rightMessages << endl;

    }
};