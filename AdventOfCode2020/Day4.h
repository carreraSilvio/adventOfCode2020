#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#pragma once
class Day4
{
public:
	void run(string inputPath) {

		//Read input, parse and calc solution
		char tree = '#';
		string openspace = ".";
		int indexIncrement = 3;
		int totalTrees = 0;

		fstream newfile;
		newfile.open(inputPath, ios::in);
		if (newfile.is_open())
		{
			string line;
			int indexPos = 0;
			while (getline(newfile, line))
			{
				cout << line << "\n";
				if (line[indexPos] == tree) {
					totalTrees++;
				}
				indexPos = (indexPos + indexIncrement) % line.length();
			}
			newfile.close();
		}

		cout << "Total trees is " << totalTrees << endl;

	}
};

