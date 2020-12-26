#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>

#pragma once
class Day6
{
public:
    void run(string inputPath) {

        //Define vars
        vector<Group> groups;

        //Read input, parse and calc solution
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            Group* currentGroup;
            groups.push_back(Group());
            currentGroup = &groups.back();
            while (getline(newfile, line))
            {
                //Finished current group
                if (line.empty()) {
                    groups.push_back(Group());
                    currentGroup = &groups.back();
                    continue;
                }
                
                //Read answers per person and add to group
                cout << "line " << line << "\n";
                currentGroup->process_person_answers(line);
                
            }
            newfile.close();
        }

        //Sum yeses
        int sumTotalYes = 0;

        for (auto group : groups)
        {
            sumTotalYes += group.totalYes;
        }


        cout << "sumTotalYes is " << sumTotalYes << endl;
    }
    
    class Group {
    public:
        int totalYes;
        vector<char> answers;

        void process_person_answers(string personData) {
            for (auto answer : personData) {
                bool isNewAnswer = std::find(answers.begin(), answers.end(), answer) == answers.end();
                if (isNewAnswer) {
                    answers.push_back(answer);
                    totalYes++;
                }
            }
        }
    };
};

