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