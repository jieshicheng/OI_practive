#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    int kind;
    cin>>n>>kind;
    vector<int> vec;
    int value;
    bool flag = false;
    for(int i = 0; i != kind; ++i)
    {
        cin>>value;
        if(value == 1)
            flag = true;
        vec.push_back(value);
    }
    if(!flag)
        cout<<0;
    else
    {   
        vector<int> dp(10000,n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= 10000; ++i)
        {
            for(int j = 0; j != vec.size(); ++j)
            {
                if(i - vec[j] >= 0 && dp[i - vec[j]] < n)
                    dp[i] = min(dp[i - vec[j]] + 1, dp[i]);
            }
            if(dp[i] == n + 1)
            {
                cout<<i - 1;
                break;
            }
        }
    }

    return 0;
}
