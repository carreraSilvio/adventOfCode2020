#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#pragma once
class Utility
{
	public:
		
		static int binary_search_find_index(vector<int> v, int target) {
			auto it = lower_bound(v.begin(), v.end(), target);
			if (it == v.end() || *it != target) {
				return -1;
			}
			else {
				size_t index = distance(v.begin(), it);
				return index;
			}
		}

		static vector<string> split(string value, char delimiter) {
			std::size_t delimeterIndex = value.find_first_of(delimiter);
			auto leftSide = value.substr(0, delimeterIndex);
			auto rightSide = value.substr(delimeterIndex+1, value.length());
			vector<string> result;
			result.push_back(leftSide);
			result.push_back(rightSide);
			return result;
		}

		static vector<std::string> splitAll(string value, char delimiter)
		{
			//vector<std::string> out;
			//// construct a stream from the string
			//fstream stream(value);

			//string s;
			//while (getline(stream, s, delimiter)) {
			//	out.push_back(s);
			//}
			//return out;

			vector<std::string> out;
			std::string::size_type beg = 0;
			for (auto end = 0; (end = value.find(delimiter, end)) != std::string::npos; ++end)
			{
				out.push_back(value.substr(beg, end - beg));
				beg = end + 1;
			}

			out.push_back(value.substr(beg));
			return out;
		}

		static int count_instances(string value, string target) {
			int total = 0;
			size_t nPos = 0; 
			while ((nPos = value.find(target, nPos)) != string::npos)
			{ 
				total++; 
				nPos += target.size();
			}
			return total;
		}
		
		
};

