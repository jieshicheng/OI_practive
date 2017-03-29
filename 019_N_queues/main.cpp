#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void DFS(vector<bool> &col, vector<bool> &main, vector<bool> &anti, int deep, int n,int &ans)
    {
        if(deep == n)
        {
            ans++;
            return ;
        }
        for(int i = 0; i != n; ++i)
        {
            if(col[i] && main[i + deep] && anti[deep + n - 1 - i])
            {
                col[i] = main[i + deep] = anti[deep + n - 1 - i] = false;
                DFS(col, main, anti, deep + 1, n, ans);
                col[i] = main[i + deep] = anti[deep + n - 1 - i] = true;
            }
        }
    }


    int solvNQueens(int n)
    {
        int ans = 0;
        vector<bool> col(n, true);
        vector<bool> main(2 * n - 1, true);
        vector<bool> anti(2 * n - 1, true);
        DFS(col, main, anti, 0, n, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    cout<<obj.solvNQueens(4)<<endl;;
	return 0;
}
