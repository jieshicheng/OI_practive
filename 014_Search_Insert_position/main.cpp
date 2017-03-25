#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int _search(vector<int> &nums, int start, int over, int target)
    {
        if(start == over)
        {
            if(target <= nums[over])
                return over;
            else
                return over + 1;
        }
        int index = (over - start) / 2 + start;
        if(nums[index] == target)
            return index;
        if(nums[index] < target)
            return _search(nums, start, index, target);
        else
            return _search(nums, index + 1, over, target);
    }


    int searchInsert(vector<int> &nums, int target)
    {
        return _search(nums, 0, nums.size() - 1, target);
    }
};

int main()
{
	return 0;
}
