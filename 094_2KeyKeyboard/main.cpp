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
    int minSteps(int n) {
        vector<int> copy(n + 1, 0);
        copy[2] = 1;
        vector<int> dp(n + 1, 0);
        dp[2] = 2;
        for( int i = 3; i <= n; ++i ) {
            dp[i] = i;
            for( int j = i - 1; j > 1; --j ) {
                if( i % j == 0 ) {
                    if( dp[i] > dp[j] + i / j ) {
                        dp[i] = dp[j] + i / j;
                        copy[i] = j;
                    }
                }
                else if( (i - j) % copy[j] == 0 ) {
                    if( dp[i] > (dp[j] + ((i - j) / copy[j]) - 1) ) {
                        dp[i] = dp[j] + (i - j) / copy[j];
                        copy[i] = copy[j];
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solv;
    cout << solv.minSteps(20) << endl;
	return 0;
}

