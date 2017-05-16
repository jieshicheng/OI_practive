#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        if(size <= 1)
            return true;
        int tempMax = 0;
        int index = 0;
        while(true)
        {
            int tempPos = 0;
            tempMax = 0;
            for(int i = nums[index]; i > 0; --i)
            {
                int temp = i + index;
                if(temp + nums[temp] > tempMax)
                {
                    tempMax = temp + nums[temp];
                    tempPos = temp;
                }
            }
            if(tempMax >= size - 1)
            {
                return true;
            }
            if(tempMax == 0)
                return false;
            index = tempPos;
        }
    }
};

int main()
{
    vector<int> nums{1,2,3,0,0,4};
    Solution obj;
    cout<<obj.canJump(nums)<<endl;
	return 0;
}

