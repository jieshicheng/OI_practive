#include <iostream>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for(int i = 0; i != size; ++i)
            dp[i][i] = nums[i];
        
        for(int len = 1; len < size; ++len)
        {
            for(int i = 0; i < size - len; ++i)
            {
                int j = i + len;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][size - 1] >= 0;
    }
};

int main()
{
	return 0;
}

