#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int size = prices.size();
        if(size <= 1)
            return 0;
        if(k > size / 2)
        {
            int ans = 0;
            for(int i = 1; i != size; ++i)
                ans += max(prices[i] - prices[i - 1] , 0);
            return ans;
        }
        vector<vector<int>> local(size , vector<int>(k + 1 , 0));
        vector<vector<int>> global(size , vector<int>(k + 1 , 0));
        int sub;
        for(int i = 1; i != size; ++i)
        {
            sub = prices[i] - prices[i - 1];
            for(int j = 1; j <= k; ++j)
            {
                locallocal[i][j] = max(local[i - 1][j] + sub , global[i - 1][j - 1] + std::max(sub , 0));
                global[i][j] = max(local[i][j] , global[i - 1][j]);
            }
        }
    }
};

int main()
{
    return 0;
}
