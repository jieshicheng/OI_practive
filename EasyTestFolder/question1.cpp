#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    int n;
    int maxIndex = 0;
    int maxTime = 0;
    int localTime = 0;
    int temp;
    cin>>n;
    if(n <= 0)
        return 0;
    for(int i = 0; i != n; ++i)
    {
        cin>>temp;
        vec.push_back(temp);
        if(i == 0)
        {
            maxIndex = 0;
            maxTime = 1;
            localTime = 1;
        }
        else
        {
            if(vec[i] == vec[i - 1])
            {
                localTime++;
                if(localTime > maxTime)
                {
                    maxTime = localTime;
                    maxIndex = i;
                }
            }
            else
                localTime = 1;
        }
    }
    cout<<vec[maxIndex];
    return 0;
}
