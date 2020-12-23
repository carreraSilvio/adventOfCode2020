#pragma once
#include <ostream>
#include <vector>
using namespace std;

class Utility
{
	public:

		int binary_search_find_index(vector<int> v, int target) {
			auto it = lower_bound(v.begin(), v.end(), target);
			if (it == v.end() || *it != target) {
				return -1;
			}
			else {
				size_t index = distance(v.begin(), it);
				return index;
			}
		}
		
		
};

ostream& operator<<(ostream& ostr, const vector<int>& vector)
{
	for (auto& i : vector) {
		ostr << " " << i;
	}
	return ostr;
}
