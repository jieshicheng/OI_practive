#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        vector<int> ans;
        int size1 = findNums.size();
        int size2 = nums.size();
        for(int i = 0; i != size1; ++i)
        {
            int j;
            bool flag = false;
            for(j = 0; j != size2; ++j)
            {
                if(findNums[i] == nums[j])
                    flag = true;
                if(flag && nums[j] > findNums[i])
                {
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(j == size2)
                ans.push_back(-1);

        }
        return ans;
    }
};

int main()
{
    vector<int> nums1{4,1,2};
    vector<int> nums2{1,3,4,2};
    Solution obj;
    auto temp = obj.nextGreaterElement(nums1, nums2);
	for(const auto &r : temp)
        cout<<r<<" ";
    cout<<endl;
    return 0;
}

