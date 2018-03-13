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
	int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for( int i = 0; i != nums.size(); ++i ) {
            if( mp.find(nums[i]) == mp.end() ) {
                int left = mp.find(nums[i] - 1) == mp.end() ? 0 : mp[nums[i] - 1];
                int right = mp.find(nums[i] + 1) == mp.end() ? 0 : mp[nums[i] + 1];
                int length = left + right + 1;
                mp.insert({nums[i], length});
                mp[nums[i] - left] = length;
                mp[nums[i] + right] = length;
                ans = max(ans, length);
            }
        }
        return ans;
    }
};

int main() {
	Solution solv;
    vector<int> nums{1,2,0,1};
    solv.longestConsecutive(nums);
    return 0;
}

