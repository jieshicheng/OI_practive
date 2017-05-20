#include <iostream>

using namespace std;

class Solution
{
public:
    int mergeStone(int n, vector<int> &nums)
    {
        if(n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for(size_t i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + nums[i];

        for(int step = 1; step < n; ++i)
        {
            for(int i = 0; i + step < n; ++i)
            {
                j = i + step;
                for(int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][k], dp[k + 1][j]);
                }
                dp[i][j] += sum[j] - sum[i] + nums[i];
            }
        }
    }
};

int main()
{
	return 0;
}

