#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>
#include <bitset>

#pragma once
class Day14
{
public:

    void run(string inputPath)
    {
        //Vars
        string mask;
        vector<char> maskAsVector;

        unsigned long long inputDecimalValue;
        bitset<36> inputBinaryValue;

        bitset<36> resultBinaryValue;
        unsigned long long resultDecimalValue;

        map<int, unsigned long long> fakeMemoryStg;


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
                if (Utils::contains_string(line, "mask"))
                {
                    vector<string> lineSplit = Utils::splitAll(line, '=');
                    mask = lineSplit.at(1);
                    Utils::trim_whitespace(mask);
                    for (auto entry : mask)
                    {
                        maskAsVector.push_back(entry);
                    }
                }
                else if (Utils::contains_string(line, "mem"))
                {
                    vector<string> lineSplit = Utils::splitAll(line, '=');

                    inputDecimalValue = stol(lineSplit.at(1));
                    inputBinaryValue = bitset<36>(inputDecimalValue);
                    resultBinaryValue = bitset<36>(inputDecimalValue);

                    auto localMask = mask;
                    reverse(localMask.begin(), localMask.end());
                    for (int i = localMask.size() - 1; i >= 0; i--)
                    {
                        if (localMask.at(i) == 'X') continue;
                        resultBinaryValue.set(i, localMask.at(i) == '1');
                    }
                    resultDecimalValue = resultBinaryValue.to_ullong();

                    //cout << "inp dec val " << inputDecimalValue << endl;
                    //cout << "inp bin val " << newInputBinaryValue << endl;
                    //cout << "--- bin msk " << mask << endl;
                    //cout << "res bin val " << newResultBinaryValue << endl;
                    //cout << "res dec val " << resultDecimalValue << endl;

                    ////'Write' to memory
                    ////Eg. mem[32] -> extract '32'
                    long memoryAddress = stol
                    (
                        Utils::splitAll
                        (
                            Utils::splitAll
                            (
                                lineSplit.at(0),
                                '['
                            ).at(1),
                            ']'
                        ).at(0)
                    );
                    
                    fakeMemoryStg.insert_or_assign(memoryAddress, resultDecimalValue);

                }
                lineId++;
            }
        }

        //Sum vals in memory
        unsigned long long sum = 0;
        for (int i = 0; i < fakeMemoryStg.size(); i++)
        {
            sum += fakeMemoryStg[i];
        }

        cout << "sum is " << sum << endl;
    }
};


