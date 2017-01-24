#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;
using std::max;

int main()
{
    vector<int> prime;
    int number;
    bool flag;

    cin>>number;
    vector<int> dp(number + 1,0);

    for(int i = 2; i <= sqrt(number); ++i)
    {
        flag = true;
        for(int j = 2; j <= sqrt(i); ++j)
        {
            if(i % j == 0)
                flag = false;
        }
        if(flag == true)
            prime.push_back(i);

    }

    for(int i = 1; i != number + 1; ++i)
    {
        int _size = prime.size();
        for(int j = 0; j != _size; ++j)
        {
            if(prime[j] <= sqrt(i) && i % prime[j] == 0)
            {
                dp[i] = max(dp[i],dp[i - 2 * prime[j]] + prime[j]);
            }
        }
    }

    cout<<dp[number];
    return 0;
}
