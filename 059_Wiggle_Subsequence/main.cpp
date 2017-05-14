#include <iostream>
#include <vector>


using namespace std;

class Solution
{
public:
	int wiggleMaxLength(vector<int> &nums)
    {
        size_t size = nums.size();
        if(size < 2)
            return size;
        size_t length = 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        size_t i = 1;
        int flag = nums[1] - nums[0] == 0 ? nums[1] - nums[0] : nums[2] - nums[0];
        if(flag > 0)
        {
            for(; i != size; ++i)
            {
                if(length % 2 == 0)
                {
                    if(nums[i] > ans[length])
                    {
                        ans.push_back(nums[i]);
                        ++length;
                    }
                    else
                    {
                        ans[length] = nums[i];
                    }
                }
                else
                {
                    if(nums[i] < ans[length])
                    {
                        ans.push_back(nums[i]);
                        ++length;
                    }
                    else
                        ans[length] = nums[i];
                }
            }
        }
        else
        {
            for(size_t i = 1; i != size; ++i)
            {
                if(length % 2 == 1)
                {
                    if(nums[i] > ans[length])
                    {
                        ans.push_back(nums[i]);
                        ++length;
                    }
                    else
                    {
                        ans[length] = nums[i];
                    }
                }
                else
                {
                    if(nums[i] < ans[length])
                    {
                        ans.push_back(nums[i]);
                        ++length;
                    }
                    else
                        ans[length] = nums[i];
                }
            }
        }
        return ans.size();
    }
};

int main()
{
    vector<int> nums{1,1,1,1,1};
    Solution obj;
    cout<<obj.wiggleMaxLength(nums)<<endl;
	return 0;
}

