#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void sortColors(vector<int> &nums)
    {
        int tail = nums.size() - 1;
        int head = 0;
        int temp;
        for(int i = 0; i != nums.size() && head <= tail; )
        {
            if(nums[i] == 0 && i >= head)
            {
                temp = nums[i];
                nums[i] = nums[head];
                nums[head] = temp;
                head++;
            }
            else if(nums[i] == 2 && i <= tail)
            {
                temp = nums[i];
                nums[i] = nums[tail];
                nums[tail] = temp;
                tail--;
            }
            else
                i++;
        }
    }
};

int main()
{
    vector<int> vec{2,0};
    Solution obj;
    obj.sortColors(vec);
    for(auto r : vec)
        cout<<r<<" ";
    cout<<endl;
	return 0;
}

