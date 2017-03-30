#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int SingleNumber(const vector<int> &nums)
    {
        int singleDog = 0;
        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            singleDog ^= *it;
        }
        return singleDog;
 
    }
};

int main()
{
    vector<int> nums{1,1,2,2,3,4,4,5,6,6,5};
    Solution obj;
    cout<<obj.SingleNumber(nums)<<endl;
    return 0;
}
