#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if(size <= 1)
            return 0;
        int local[size][3] = {0};
        int global[size][3] = {0};
        int sub;
        for(int i = 1; i != size; ++i)
        {
            sub = prices[i] - prices[i - 1];
            for(int j = 1; j != 3; ++j)
            {
                local[i][j] = (local[i - 1][j] + sub) > (global[i - 1][j - 1] + std::max(sub , 0)) ? local[i - 1][j] + sub : (global[i - 1][j - 1] + std::max(sub , 0));
                global[i][j] = local[i][j] > global[i - 1][j] ? local[i][j] : global[i - 1][j];
            }
        }
        return global[size - 1][2];
    }
};


int main()
{
    return 0;
}
