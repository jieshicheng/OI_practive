#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void swap(int &lhs, int &rhs)
    {
        int temp = lhs;
        lhs = rhs;
        rhs = temp;
    }

    int recursion(vector<int> &nums, int beg, int ed, int k)
    {
        if(beg == ed)
            return nums[beg];
        int i = beg + 1;
        int j = ed;
        while(i < j)
        {
            if(nums[i] > nums[beg])
            {
                swap(nums[i], nums[j]);
                --j;
            }
            else
                ++i;
        }
        if(nums[i] < nums[beg])
            swap(nums[i], nums[beg]);
        else
        {
            i--;
            swap(nums[i], nums[beg]);
        }
        if(i == k)
            return nums[i];
        if(k > i)
            return recursion(nums, i + 1, ed, k);
        if(k < i)
            return recursion(nums, beg, i - 1, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        return recursion(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main()
{
    vector<int> nums{7,9,3,2,5,1,6};
    Solution obj;
    cout<<obj.findKthLargest(nums, 2);
	return 0;
}

