#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;
using std::max;

void solv_2(const vector<int> &number,const vector<int> &amout,int siz,int sum);
void solv_1(const vector<int> &number,const vector<int> &amout,int siz,int sum);

int main()
{
    int siz;
    int sum;
    vector<int> number;
    vector<int> amout;

    cin>>siz>>sum;
    for(int i = 0; i != siz; ++i)
    {
        int temp;
        cin>>temp;
        number.push_back(temp);
    }
    for(int i = 0; i != siz; ++i)
    {
        int temp;
        cin>>temp;
        amout.push_back(temp);
    }

    solv_2(number,amout,siz,sum);

    return 0;
}

/**
 *  solve function 1
 *  but if use dp store bool,it lost a lot of message.because it can store more message instead of bool;
 */
void solv_1(const vector<int> &number,const vector<int> &amout,int siz,int sum)
{
    vector<vector<bool>> dp(siz + 1,vector<bool>(sum + 1,false));
    for(int i = 0; i <= siz; ++i)
        dp[i][0] = true;

    for(int i = 1; i <= siz; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            for(int k = 1; k <= amout[i - 1]; ++k)
            {
                if(j - k * number[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - k * number[i - 1]];
            }
        }
    }

    cout<<dp[siz][sum];
}


/**
 *  Do optimization on solv_1's basis
 *  dp[i][j] store how many number of i surplus
 */
void solv_2(const vector<int> &number,const vector<int> &amout,int siz,int sum)
{
    vector<vector<int>> dp(siz + 1,vector<int>(sum + 1,-1));
    dp[0][0] = 0;
    for(int i = 1; i <= siz; ++i)
    {
        dp[i][0] = amout[i - 1];
    }

    for(int i = 1; i <= siz; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            for(int k = 1; k <= amout[i - 1] && j >= k * number[i - 1]; ++k)
            {
                if(dp[i - 1][j] != -1)
                {
                    dp[i][j] = amout[i - 1];
                    break;
                }
                else if(dp[i - 1][j - k * number[i - 1]] != -1)
                {
                    dp[i][j] = amout[i - 1] - k;
                    break;
                }

            }
        }
    }

    cout<<dp[siz][sum - 1];
}
