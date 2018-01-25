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
    int deleteAndEarn(const vector<int> &nums) {
        vector<int> dp(10000, 0);
        for( const auto &r : nums )
            dp[r] += r;
        int skipi = 0, takei = 0, skip = 0, take = 0;
        for( int i = 0; i != 10000; ++i ) {
            skipi = max(skip, take);
            takei = skip + dp[i];
            skip = skipi;
            take = takei;
        }
        return max(skip, take);
    }
};

int main() {
    Solution solv;
    cout << solv.deleteAndEarn({3,1}) << endl;
	return 0;
}

