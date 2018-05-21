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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for( int i = 0; i != nums.size(); ++i ) {
            sum += nums[i];
        }
        int target = sum / 2;
        if( target * 2 != sum )
            return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for( int i = 0; i != nums.size(); ++i ) {
            for( int j = target; j > 0; --j ) {
                if( j - nums[i] >= 0 )
                    dp[j] = dp[j] || dp[j - nums[i]];
            } 
        }
        return dp[target];
    }
};

int main() {
	vector<int> nums(350, 100);
    Solution solv;
    cout << solv.canPartition(nums) << endl;
    return 0;
}

