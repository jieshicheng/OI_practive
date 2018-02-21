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
	int rob(vector<int>& nums) {
        if( nums.size() == 1 )
            return nums[0];
        if( nums.empty() )
            return 0;
        else
            return max(solv(nums, 0, nums.size() - 1), solv(nums, 1, nums.size()));
    }
    int solv(vector<int> &nums, int begin, int end) {
        int pre = 0, cur = 0;
        int temp;
        for( int i = begin; i != end; ++i ) {
            temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main() {
	return 0;
}

