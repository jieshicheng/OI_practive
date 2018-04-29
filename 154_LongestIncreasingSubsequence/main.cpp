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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for( int i = 0; i != nums.size(); ++i ) {
            auto iter = lower_bound(ans.begin(), ans.end(), nums[i]);
            if( iter == ans.end() )
                ans.push_back(nums[i]);
            else
                *iter = nums[i];
        }
        return ans.size();
    }
};

int main() {
	return 0;
}

