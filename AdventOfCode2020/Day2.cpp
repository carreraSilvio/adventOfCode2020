#include "day2.h"
#include <iostream>// std::cout
#include <fstream>
#include <vector>

using namespace std;

void Day2::run(string inputPath)
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
			auto entry = InputEntryInfo(line);
			entries.push_back(entry);
			cout << line << "\n";
		}
		newfile.close();
	}
}