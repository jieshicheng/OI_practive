#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        int size = prices.size();
        if(size == 0)
            ;
        else
        {
            int earn = 0;
            for(int i = 0; i != size - 1; ++i)
            {
                earn = prices[i + 1] - prices[i];
                if(earn > 0)
                    sum += earn;
            }
        }
        return sum;
    }
};
