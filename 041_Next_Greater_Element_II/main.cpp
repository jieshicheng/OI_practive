#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> ans(size, -1);
        stack<int> stk;

        for(int i = 0; i != 2 * size; ++i)
        {
            int ele = nums[i % size];
            while( !stk.empty() && nums[stk.top()] < ele)
            {
                ans[stk.top()] = ele;
                stk.pop();
            }
            if(i < size)
                stk.push(i);
        }
        return ans;
    }
};

int main()
{
	return 0;
}

