#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
    int siz;
    int max_;
    int div;

    cin>>siz>>max_>>div;

    vector<vector<int>> dp(siz + 1,vector<int>(max_ + 1,0));
    for(int i = 0; i <= max_; ++i)
        dp[0][i] = 1;

    for(int i = 1; i <= siz; ++i)
    {
        for(int j = 1; j <= max_; ++j)
        {
            if(i >= j)
                dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % div;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    cout<<dp[siz][max_];
    return 0;
}
