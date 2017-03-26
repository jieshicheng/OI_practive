#include <iostream>

using namespace std;

class Solution
{
public:
    void DFS(int now, int goals, int &ans)
    {
        if(now == goals)
        {
           ans++;
           return ;
        }
        if(goals - now >= 2)
        {
            DFS(now + 2, goals, ans);
            DFS(now + 1, goals, ans);
        }
        if(goals - now == 1)
            DFS(now + 1, goals, ans);

    }

    int climbStairs(int n)
    {
        int pre = 0;
        int suf = 1;
        for(int i = 2; i <= n; ++i)
        {
            int temp = pre;
            pre = suf;
            suf = suf + temp;
        }
        return suf;
    }
};

int main()
{
	return 0;
}
