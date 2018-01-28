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
    int maxProfit(vector<int>& prices) {
        int selli_2 = 0, selli_1 = 0, buyi_1 = INT_MIN;
        int buy = 0, sell = 0;
        size_t size = prices.size();
        int temp;
        for( int i = 0; i != size; ++i ) {
            temp = prices[i];
            buy = max(buyi_1, selli_2 - temp);
            sell = max(buyi_1 + temp, selli_1);
            selli_2 = selli_1;
            selli_1 = sell;
            buyi_1 = buy;
        }
        return max(buy, sell);
    }
};

int main() {
	return 0;
}

