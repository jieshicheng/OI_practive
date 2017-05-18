#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &M, int beg)
    {
        for(size_t i = 0; i != M[beg].size(); ++i)
        {
            if(M[beg][i] == 1 && beg != i)
            {
                M[beg][i] = 0;
                M[i][beg] = 0;
                M[i][i] = 0;
                M[beg][beg] = 0;
                dfs(M, i);
            }
        }
        return ;
    }

    int findCircleNum(vector<vector<int>> &M)
    {
        int ans =  0;
        for(size_t i = 0; i != M.size(); ++i)
        {
            for(size_t j = 0; j != M[i].size(); ++j)
            {
                if(M[i][j] == 1)
                {
                    ++ans;
                    dfs(M, i);
                }
            }
        }
        return ans;
    }
};


int main()
{
    return 0;
}
