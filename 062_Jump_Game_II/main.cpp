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
        int times = 0;
        while(true)
        {
            times++;
            int tempPos = 0;
            tempMax = 0;
            for(int i = nums[index]; i > 0; --i)
            {
                int temp = i + index;
                if(temp + nums[temp] > tempMax)
                {
                    tempMax = temp + nums[temp];
                    tempPos = temp;
                    if(tempPos >= size - 1)
                        return times;
                }
            }
            if(tempPos >= size - 1)
            {
                break;
            }
            index = tempPos;
        }
        return times;
    }
};

int main()
{
    vector<int> nums{1,2,3,0,0,4};
    Solution obj;
    cout<<obj.canJump(nums)<<endl;
	return 0;
}

