#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        map<int, int> dp;
        dp.insert({0, -1});
        int size = nums.size();
        for(int i = 0; i != size; ++i)
        {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if(dp.count(mod) && (i - dp.find(mod)->second) > 1)
                return true;
            else
                dp.insert({mod,i});
        }
        return false;
    }
};

int main()
{
	return 0;
}

