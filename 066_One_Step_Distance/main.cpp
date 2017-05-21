#include <iostream>

using namespace std;

class Solution
{
public:
    int exgcd(int a, int b, int &x, int &y)
    {
        if(b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        int ans = exgcd(b, a % b, y, x);
        y = y - (a / b) * x;
        return ans;
    }

    int findSmallerStep()
    {
        int x, y;
        exgcd(127, 97, x, y);
        return abs(x) + abs(y);
    }
};

int main()
{
    Solution obj;
    cout<<obj.findSmallerStep()<<endl;
	return 0;
}

