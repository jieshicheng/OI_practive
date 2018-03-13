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
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int times = nums.size() / 2;
        int max = 0;
        int ans;
        for( int i = 0; i != nums.size(); ++i ) {
            mp[nums[i]]++;
            if( mp[nums[i]] > max ) {
                max = mp[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }	
};

int main() {
	return 0;
}

