#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxSubarray(vector<int> &nums)
    {
        int _size = nums.size();
        vector<int> dp(_size, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i != _size; ++i)
        {
            if(dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
            if(ans < dp[i])
                ans = dp[i];
        }
        return ans;
    }
};

int main()
{
	return 0;
}
