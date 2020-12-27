#include <iostream>// std::cout
#include <string>
#include "Utils.h"
#include <fstream>
#include <vector>

using namespace std;

#pragma once
class Day2
{
public:
    class InputEntryInfo {  //eg "4-7 z: zzzfzlzzz" 
    public:
        int min = 0; //eg 4
        int max = 0;//eg 7
        string target = "";//eg z
        string value = ""; //eg zzzfzlzzz
        int total;
        bool isValid;

        InputEntryInfo(string fullValue) {

            std::size_t delimeterIndex = fullValue.find_first_of(":");
            auto leftSide = fullValue.substr(0, delimeterIndex);
            auto rightSide = fullValue.substr(delimeterIndex + 1, fullValue.length());
            rightSide.erase(remove(rightSide.begin(), rightSide.end(), ' '), rightSide.end());

            vector<string> leftSideSplitted = Utils::divide(leftSide, ' ');
            vector<string> minMaxSplitted = Utils::divide(leftSideSplitted[0], '-');

            min = stoi(minMaxSplitted[0]);
            max = stoi(minMaxSplitted[1]);
            target = leftSideSplitted[1];
            value = rightSide;

            //cout << "min is " << min << endl;
            //cout << "max is " << max << endl;
            //cout << "target is " << target << endl;
            //cout << "value is " << value << endl;

            total = Utils::count_instances(value, target);
            isValid = (total >= min) && (total <= max);
            cout.setf(std::ios::boolalpha);
            //cout << "total is " << total << endl;
            //cout << "valid is " << valid << endl;
        }
    };

    void run(string inputPath)
    {
        //Read input and parse format "4-7 z: zzzfzlzzz"
        vector<InputEntryInfo> entries;
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            while (getline(newfile, line))
            {
                cout << line << "\n";
                auto entry = InputEntryInfo(line);
                entries.push_back(entry);
            }
            newfile.close();
        }

        //Count valid
        int countValid = 0;
        for (auto entry : entries) {
            if (entry.isValid) {
                countValid++;
            }
        }
        cout << "count valid " << countValid << endl;
    }

    
};