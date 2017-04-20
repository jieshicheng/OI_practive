#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    pair<int,int> _calulate(const string &s)
    {
        int zero = 0;
        int ones = 0;
        for(const auto &c : s)
        {
            if(c == '0')
                ++zero;
            else
                ++ones;
        }
        return {zero,ones};
    }


	int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        pair<int,int> temp;
        for(int s = 1; s <= size; ++s)
        {
            temp = _calulate(strs[s - 1]);
            for(int i = m; i >= temp.first; --i)
            {
                for(int j = n; j >= temp.second; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - temp.first][j - temp.second]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    Solution obj;
    cout<<obj.findMaxForm(strs, 5, 3);
	return 0;
}

