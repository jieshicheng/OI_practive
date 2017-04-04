#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        if(size <= 1)
            return size;
        int index = 1;
        for(int i = 1; i != size; ++i)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[index++] = nums[i];
            }
        }
        return index + 1;
    }
};

int main()
{
    vector<int> vec{1,1,1,1,1,1,2,2,2,3,4,4,5,6};
    Solution obj;
    cout<<obj.removeDuplicates(vec);
	return 0;
}

