#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int length = nums.size();
        for(int i = 0; i < length; )
        {
            if(nums[i] == val)
                   nums[i] = nums[--length];
            else
                ++i;
        }
        return length;
    }
};

int main()
{
	return 0;
}
