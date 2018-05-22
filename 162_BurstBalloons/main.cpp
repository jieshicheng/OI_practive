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
	int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<int> vec(size + 2, 0);
        for( int i = 1; i <= size; ++i ) {
            vec[i] = nums[i - 1];
        }
        vec[0] = vec[size + 1] = 1;
        
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
        
        for( int step = 2; step <= size + 1; ++step ) {
            for( int left = 0; left <= size + 1 - step; ++left ) {
                int right = left + step;
                for( int i = left + 1; i < right; ++i )
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + vec[left] * vec[right] * vec[i]);
            }
        }
        return dp[0][size + 1];
    }
};

int main() {
	return 0;
}

