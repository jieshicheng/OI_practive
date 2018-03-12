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
        if( prices.size() <= 1 )
            return 0;
        int smallSell = prices[0];
        int ans = 0;
        for( int i = 1; i != prices.size(); ++i ) {
            ans = max(prices[i] - smallSell, ans);
            smallSell = min(smallSell, prices[i]);
        }
        return ans;
    }	
};

int main() {
	return 0;
}

