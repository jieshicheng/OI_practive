#include <iostream>
#include <vector>
#include <cmath>

using std::max;
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int siz;
    vector<int> number;

    cin>>siz;
    for(int i = 0; i != siz; ++i)
    {
        int temp;
        cin>>temp;
        number.push_back(temp);
    }

    vector<int> dp(siz + 1,1);
    dp[0] = 0;

    for(int i = 2; i <= siz; ++i)
    {
        for(int j = 0; j != i; ++j)
        {
            if(number[i - 1] > number[j])
                dp[i] = max(dp[i],dp[j + 1] + 1);
        }
    }

    cout<<dp[siz];
    return 0;
}
