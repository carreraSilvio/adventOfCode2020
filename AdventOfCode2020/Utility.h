#pragma once
#include <ostream>
#include <vector>
using namespace std;

static class Utility
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
		
		
};

ostream& operator<<(ostream& ostr, const vector<int>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}
