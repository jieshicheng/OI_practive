#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        while(x != 0)
        {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        x = ans;
        if(x == ans)
            return x;
        else
            return 0;
    }
};

int main()
{
    Solution obj;
    cout<<obj.reverse(-123)<<endl;
    return 0;
}
