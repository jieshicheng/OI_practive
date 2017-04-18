#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    vector<bool> dp(1000,false);
    bool flag = false;
    int minmum = 0xffffff;
    for(int i = 0; i != n; ++i)
    {
        int temp;
        cin>>temp;
        if(temp % 2 != 0)
            flag = true;
        minmum = temp > minmum ? minmum : temp;
        vec.push_back(temp);
        dp[temp] = true;
    }
    if(!flag)
    {
        cout<<"INF";
        return 0;
    }
    int length = 0;
    int ans = 0;
    for(int i = 1; i != 1000; ++i)
    {
        if(length == minmum)
        {
            cout<<ans;
            break;    
        }
        if(!dp[i])
        {
            for(int j = 0; j != vec.size(); ++j)
            {
                if(i - vec[j] >= 0 && dp[i - vec[j]])
                {
                    dp[i] = true;
                    break;
                }
            }
            if(!dp[i])
            {
                length = 0;
                ans++;
            }
            else
                length++;
        }
        else
            length++;
    }


    return 0;
}
