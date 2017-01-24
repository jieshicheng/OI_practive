#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    int number;
    cin>>number;
    vector<int> dp(number + 1,0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= number; ++i)
    {
        if(i % 2 == 1)
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + dp[i / 2];
    }
    cout<<dp[number];
    return 0;
}
