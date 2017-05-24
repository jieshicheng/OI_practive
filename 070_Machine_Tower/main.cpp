#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberA;
    int numberB;
    int ans;

    bool check(vector<char> strs, int a, int b)
    {
        vector<char> str;
        while(true)
        {
            if( a > numberA || b > numberB )
                return false;
            if(strs.size() == 1 && a == numberA && b == numberB)
                return true;

            for(int i = 0; i < strs.size() - 1; ++i)
            {
                if(strs[i] == strs[i + 1])
                {
                    str.push_back('A');
                    ++a;
                }
                else
                {
                    ++b;
                    str.push_back('B');
                }
            }
            strs = str;
            str.clear();
        }
    }
    void dfs(vector<char> strs, int a, int b, int number)
    {
        if((a + b) == number)
        {
            if( check(strs, a, b) )
            {
                ++ans;
            }
            return ;
        }
        if(a < numberA)
        {
            strs.push_back('A');
            dfs(strs, a + 1, b, number);
            strs.pop_back();
        }
        if(b < numberB)
        {
            strs.push_back('B');
            dfs(strs, a, b + 1, number);
            strs.pop_back();
        }
    }

    int findMaxWays(int a, int b)
    {
        numberA = a;
        numberB = b;
        ans = 0;
        vector<int> level(50, 0);
        int number;
        for(int i = 1; i != 50; ++i)
        {
            level[i] = i + level[i - 1];
            if(level[i] == (a + b))
            {
                number = i;
                break;
            }
        }
        vector<char> rows;
        dfs(rows, 0, 0, number);
        return ans;
    }
};

int main()
{
    Solution obj;
    cout<<obj.findMaxWays(20, 16)<<endl;
	return 0;
}

