#include <iostream>
#include <vector>

using namespace std;

bool test(int n, vector<bool> &vec)
{
    if(vec[n] == false)
        return false;
    else
    {
        for(int i = 0; i != n; ++i)
        {
            int ans = i;
            int temp = i;
            while(temp)
            {
                ans += temp % 10;
                temp /= 10;
            }
            if(ans == n)
                return false;
        }
    }
    return true;
}



int main()
{
    int n;
    cin>>n;
    if(n <= 1)
        return 0;
    vector<bool> vec(10000,true);
    for(int i = 1; i != n; ++i)
    {
        if(test(i, vec))
        {
            cout<<i<<endl;
            int ans = i;
            while(ans < 10000)
            {
                int temp = ans;
                while(temp)
                {
                    ans = ans + temp % 10;
                    temp /= 10;
                }
                vec[ans] = false;
            }
        }
    }

    return  0;
}
