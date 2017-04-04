#include <iostream>
#include <cmath>

using namespace std;

bool test(long long n)
{
    for(long long i = 2; i <=sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    int time = 0;
    int ans = 1;
    long long i = 2;
    cin>>n;
    while(1)
    {
        if(time == n)
            break;
        if(test(i))
        {
            time++;
            ans = (ans * i % 50000) % 50000;
        }
        ++i;
    }
    cout<<ans;
    return 0;
}
