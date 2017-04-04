#include <iostream>

using namespace std;

bool test(long long i, long long number)
{
    bool flag = false;
    while(number % i)
    {
        long long temp = number % i;
        number = i;
        i = temp;
        if(i == 1)
            flag = true;
    }
    return flag;
}


long long solv(long long n)
{
    long long number1 = n;
    long long number2 = 0;
    long long number3 = 0;
    for(long long i = n - 1; i != 0; --i)
    {
        if(number2 == 0 && test(i, number1))
        {
            number2 = i;
            continue;
        }
        if(number2 != 0 && test(i, number2) && test(i, number1))
        {
            number3 = i;
            break;
        }
    }
    long long ans = number1 * number2 * number3;
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    long long ans = 0;
    long long temp;
    for(int i = 0; i <= n / 3; ++i)
    {
        temp = solv(n - i);
        ans = temp > ans ? temp : ans;
    }
    cout<<ans;
    return 0;
}
