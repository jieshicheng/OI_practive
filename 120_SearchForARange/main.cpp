#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        if( begin == nums.end() )
            return {-1, -1};
        if( *begin == target )
            return {begin - nums.begin(), end - nums.begin() - 1};
        else
            return {-1, -1};
    }
};

int main() {
	return 0;
}

