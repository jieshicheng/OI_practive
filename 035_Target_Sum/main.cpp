#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> memory(20, vector<int>(1000, -1));

    int recursion(vector<int> &nums, int beg, int end, int s)
    {
        if(beg == end)
        {
            int ans = 0;
            if(nums[end] == s)
                ans++;
            if(-nums[end] == s)
                ans++;
            return ans;

        }        
        return recursion(nums, beg, end - 1, s + nums[end]) +
                recursion(nums, beg, end - 1, s - nums[end]);
    }

    int findTargetSumWays(vector<int> &nums, int s)
    {
        int size = nums.size();
        if(!size)
            return 0;
        return recursion(nums, 0, size - 1, s);
    }

};

int main()
{
	return 0;
}

