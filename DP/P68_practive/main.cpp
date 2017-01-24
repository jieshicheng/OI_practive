#include <iostream>
#include <vector>
#include <cmath>

using std::min;
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int siz;
    int number;
    int div;
    vector<int> vec;

    cin>>siz>>number;
    vector<vector<int>> dp(siz + 1,vector<int>(number + 1,0));
    for(int i = 0; i != siz; ++i)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>div;

    for(int i = 0; i <= number; ++i)
        dp[i][0] = 1;

    for(int i = 1; i <= siz; ++i)
    {
        for(int j = 1; j <= number; ++j)
        {
            for(int k = 0; k <= min(j,vec[i - 1]); ++k)
            {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    cout<<dp[siz][number];
    return 0;
}
