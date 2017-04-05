#include <iostream>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        if(size <= 2)
            return size;
        int index = 1;
        bool flag = true;
        for(int i = 1; i != size; ++i)
        {
            if(nums[i] == nums[i - 1])
            {
                if(flag)
                {
                    nums[index++] = nums[i];
                    flag = false;
                }
            }
            else
            {
                flag = true;
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main()
{
	return 0;
}

