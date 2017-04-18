#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    if(n <= 0)
        return 0;
    vector<int> vec(n,0);
    vector<int> gloabl(n,0);
    vector<int> local(n, 0);
    for(int i = 0; i != n; ++i)
    {
        int temp;
        cin>>temp;
        vec[i] = temp;
    }
    if(vec[0] % k == 0)
    {
        gloabl[0] = 1;
        local[0] = 1;
    }
    for(int i = 1; i != n; ++i)
    {
        if(vec[i] % k == 0)
        {
            gloabl[i] = gloabl[i - 1] + 1 + local[i - 1];
            local[i] = local[i - 1] + 1;
        }
        else
        {
            int sum = vec[i];
            for(int j = i - 1; j >= 0; --j)
            {
                sum += vec[j];
                if(sum % k == 0)
                    local[i]++;
            }
            gloabl[i] = gloabl[i - 1] + local[i];
        }
    }
    cout<<gloabl[n - 1];
    return 0;
}
