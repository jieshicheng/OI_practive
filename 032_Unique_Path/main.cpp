#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*       用的DFS，不过测试用例高达100 100,所以复杂度爆棚
    int ans = 0;
    int row[2] = {0,1};
    int col[2] = {1,0};

    void DFS(int x, int y, int m, int n)
    {
        if(x == m && y == n)
        {
            ++ans;
            return ;
        }
        for(int i = 0; i != 2; ++i)
        {
            if(x + row[i] <= m && y + col[i] <= n)
                DFS(x + row[i], y + col[i], m, n);
        }
    }

    int uniquePaths(int m, int n)
    {
        DFS(0,0,m - 1,n - 1);
        return ans;
    }
    */

    //  这道题用DP才是王道

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> vec(m, vector<int>(n,0));
        vec[0][0] = 1;
        for(int i = 0; i != m; ++i)
        {
            for(int j = 0; j != n; ++j)
            {
                if(i - 1 >= 0)
                    vec[i][j] += vec[i - 1][j];
                if(j - 1 >= 0)
                    vec[i][j] += vec[i][j - 1];
            }
        }
        return vec[m - 1][n - 1];
    }
};

int main()
{
    Solution obj;
    cout<<obj.uniquePaths(3,7);
	return 0;
}

