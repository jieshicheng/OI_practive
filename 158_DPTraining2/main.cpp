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
    pair<int, int> getMinMax(const vector<int> &coins, int target) {
        vector<int> dp1(target + 1, -1);
        dp1[0] = 0;
        recurMax(dp1, coins, target);

        vector<int> dp2(target + 1, -1);
        dp2[0] = 0;
        recurMin(dp2, coins, target);
        return {dp1[target], dp2[target]};
    }
    int recurMin(vector<int> &dpMin, const vector<int> &coins, int target) {
        if( dpMin[target] != -1 )
            return dpMin[target];
        dpMin[target] = INT_MAX - 1;
        for( int i = 0; i != coins.size(); ++i ) {
            if( target >= coins[i] )
                dpMin[target] = min(recurMin(dpMin, coins, target - coins[i]) + 1, dpMin[target]);
        }
        return dpMin[target];
    }

    int recurMax(vector<int> &dpMax, const vector<int> &coins, int target) {
        if( dpMax[target] != -1 )
            return dpMax[target];
        dpMax[target] = 0;
        for( int i = 0; i != coins.size(); ++i ) {
            if( target >= coins[i] )
                dpMax[target] = max(recurMax(dpMax, coins, target - coins[i]) + 1, dpMax[target]);
        }
        return dpMax[target];
    }
};

int main() {
    Solution solv;
    pair<int, int> ans = solv.getMinMax({11,22,34,10,12}, 12314);
	cout << ans.first << " " << ans.second << endl;
    return 0;
}

