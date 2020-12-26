#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#pragma once
class Day4
{
public:
	void run(string inputPath) {

		//Define vars
		int totalValidPassports = 0;

        const vector<string> NECESSARY_FIELDS = 
        {
            "byr",
            "iyr", 
            "eyr", 
            "hgt", 
            "hcl",
            "ecl",
            "pid"
        };
        vector<string> passport;

        //Read input, parse and calc solution
		fstream newfile;
		newfile.open(inputPath, ios::in);
		if (newfile.is_open())
		{
			string line;
			while (getline(newfile, line))
			{
                //If has finished reading current passport data
                if (line.empty()) 
                {
                    ValidatePassport(NECESSARY_FIELDS, passport, totalValidPassports);
                    continue;
                }

                //Read all fields in current passport
				cout << "line " << line << "\n";
                auto entries = Utils::splitAll(line, ' ');
                for (auto entry : entries) {
                    vector<string> entrySplit = Utils::splitAll(entry, ':');
                    cout << "field read is " << entrySplit[0] << endl;
                    passport.push_back(entrySplit[0]);
                }
			}
			newfile.close();
		}
        ValidatePassport(NECESSARY_FIELDS, passport, totalValidPassports);

		cout << "Total valid is " << totalValidPassports << endl;
	}

    
    void ValidatePassport(const std::vector<std::string>& NECESSARY_FIELDS, std::vector<std::string>& passport, int& totalValidPassports)
    {
        cout << "--Finished reading data for current passport--" << endl;
        //Check if all necessary fields are present
        bool allNecessaryFieldsPresent = true;
        for (auto necessaryField : NECESSARY_FIELDS) {
            if (find(passport.begin(), passport.end(), necessaryField) == passport.end()) {
                cout << "###field " << necessaryField << " not found" << endl;
                allNecessaryFieldsPresent = false;
                break;
            }
        }

        if (allNecessaryFieldsPresent)
        {
            totalValidPassports++;
        }

        passport.clear();
    }

    class Passport {  
    public:
        int min = 0; //eg 4
        int max = 0;//eg 7
        string target = "";//eg z
        string value = ""; //eg zzzfzlzzz
        int total;
        bool isValid;

        Passport(string fullValue) {

            std::size_t delimeterIndex = fullValue.find_first_of(":");
            auto leftSide = fullValue.substr(0, delimeterIndex);
            auto rightSide = fullValue.substr(delimeterIndex + 1, fullValue.length());
            rightSide.erase(remove(rightSide.begin(), rightSide.end(), ' '), rightSide.end());

            vector<string> leftSideSplitted = Utils::split(leftSide, ' ');
            vector<string> minMaxSplitted = Utils::split(leftSideSplitted[0], '-');

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
};

