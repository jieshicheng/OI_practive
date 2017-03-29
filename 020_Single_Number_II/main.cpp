#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &vec)
    {
        int ones = 0, twos = 0;
        for(int i = 0; i < vec.size(); ++i)
        {
            ones ^= vec[i] & ~twos;
            twos ^= vec[i] & ~ones;
        }
        return ones;
    }
};

int main()
{
    vector<int> vec{1,1,1,2,3,2,2};
    Solution obj;
    cout<<obj.singleNumber(vec)<<endl;
	return 0;
}
