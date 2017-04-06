#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> vec;
        for(int i = 0; i != 1 << n; ++i)
            vec.push_back(i / 2 ^ i);
        
        return vec;
    }
};

int main()
{
    Solution obj;
    auto vec = obj.grayCode(5);
	for(auto r : vec)
        cout<<r<<" ";
    cout<<endl;
    return 0;
}

