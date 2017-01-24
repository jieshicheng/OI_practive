#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

const int Max = 0x7fffffff;

int solv(const vector<int> &pos,int number,int _size);

int main()
{
    int number;
    int _size;
    cin>>number>>_size;
    vector<int> pos(_size + 2,0);
    for(int i = 1; i <= _size; ++i)
    {
        int temp;
        cin>>temp;
        pos[i] = temp;
    }
    pos[0] = 0;
    pos[_size + 1] = number + 1;
    
    cout<<solv(pos,number,_size);
    return 0;
}

int solv(const vector<int> &pos,int number,int _size)
{
    vector<vector<int>> dp(_size + 1,vector<int>(_size + 2,Max));
    //initialization,cause dp[i][j] equal (i,j)
    for(int i = 0; i <= _size; ++i)
    {
        dp[i][i + 1] = 0;
    }

    for(int step = 2; step <= _size + 1; ++step)
    {
        for(int i = 0; i + step <= _size + 1; ++i)
        {
            int j = i + step;
            int minValue = Max;
            for(int k = i + 1; k < j; ++k)
            {
                minValue = min(minValue,dp[i][k] + dp[k][j]);
            }
            dp[i][j] = minValue + pos[j] - pos[i] - 2;
        }
    }

    return dp[0][_size + 1];
}
