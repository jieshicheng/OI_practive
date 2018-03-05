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
	int search(vector<int>& nums, int target) {
        if( nums.empty() )
            return -1;
        if( nums.size() == 1 )
            return nums[0] == target ? 0 : -1;
        int index = nums.size();
        for( int i = 1; i < nums.size(); ++i ) {
            if( nums[i] < nums[i - 1] ) {
                index = i;
                break;
            }
        }
        if( target >= nums[0] ) {
            auto find = lower_bound(nums.begin(), nums.begin() + index, target);
            if( *find == target )
                return find - nums.begin();
        }
        else {
            auto find = lower_bound(nums.begin() + index, nums.end(), target);
            if( *find == target )
                return find - nums.begin();
        }
        return -1;
    }
};

int main() {
	return 0;
}

