#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int mergeStone(int n, vector<int> &nums)
    {
        if(n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0xfffff));
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        dp[0][0] = 0;
        for(size_t i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + nums[i];
            dp[i][i] = 0;
        }
        for(int step = 1; step < n; ++step)
        {
            for(int i = 0; i + step < n; ++i)
            {
                int j = i + step;
                for(int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
                }
                dp[i][j] += sum[j] - sum[i] + nums[i];
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    int n = 7;
    vector<int> nums{13,7,8,16,21,4,18};
    Solution obj;
    cout<<obj.mergeStone(n, nums)<<endl;
	return 0;
}

