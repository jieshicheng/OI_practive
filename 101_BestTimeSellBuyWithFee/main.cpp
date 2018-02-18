#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;



class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        if( size < 2 )
            return 0;
        int preBuy = -prices[0] - fee;
        int preSell = 0;
        int buy;
        int sell;
        for( int i = 1; i != size; ++i ) {
            buy = max(preSell - prices[i] - fee, preBuy);
            sell = max(preBuy + prices[i], preSell);
            preBuy = buy;
            preSell = sell;
        }
        return max(buy, sell);
    }
};

int main() {
	return 0;
}

