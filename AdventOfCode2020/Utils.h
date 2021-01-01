#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#pragma once
class Utils
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

		static bool is_number(const std::string& s)
		{
			std::string::const_iterator it = s.begin();
			while (it != s.end() && std::isdigit(*it)) ++it;
			return !s.empty() && it == s.end();
		}

		static vector<string> divide(string value, char delimiter) {
			std::size_t delimeterIndex = value.find_first_of(delimiter);
			auto leftSide = value.substr(0, delimeterIndex);
			auto rightSide = value.substr(delimeterIndex+1, value.length());
			vector<string> result;
			result.push_back(leftSide);
			result.push_back(rightSide);
			return result;
		}

		static vector<string> divide_by_string(string value, string delimiter) {
			size_t delimeterIndex = value.find(delimiter);
			auto leftSide = value.substr(0, delimeterIndex);
			auto rightSide = value.substr(delimeterIndex + delimiter.length(), value.length());
			vector<string> result;
			result.push_back(leftSide);
			result.push_back(rightSide);
			return result;
		}

		static bool contains_string(string value, string target) {
			size_t targetIndex = value.find(target);
			return targetIndex != string::npos;
		}

		static void trim_whitespace(string& s)
		{
			size_t p = s.find_first_not_of(" \t");
			s.erase(0, p);

			p = s.find_last_not_of(" \t");
			if (string::npos != p)
				s.erase(p + 1);
		}

		static string find_and_replace(string value, string target, string substitute) {
			size_t targetIndex = value.find(target);
			bool targetFound = targetIndex != string::npos;
			if (!targetFound) {
				return value;
			}

			value.replace(targetIndex, targetIndex + target.size(), substitute);
			return value;
		}

		static vector<std::string> splitAll(string value, char delimiter)
		{
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


ostream& operator<<(ostream& ostr, const vector<int>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}

ostream& operator<<(ostream& ostr, const vector<string>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}

ostream& operator<<(ostream& ostr, const vector<long>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}

ostream& operator<<(ostream& ostr, const vector<char>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}