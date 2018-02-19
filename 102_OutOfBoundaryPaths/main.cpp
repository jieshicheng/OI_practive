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
	int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<long>>> dp(N + 1, vector<vector<long>>(m, vector<long>(n, 0)));
        for( int step = 1; step <= N; ++step ) {
            for( int _m = 0; _m != m; ++_m ) {
                for( int _n = 0; _n != n; ++_n ) {
                    dp[step][_m][_n] = ((_m == 0 ? 1 : dp[step - 1][_m - 1][_n]) + (_m == m - 1 ? 1 : dp[step - 1][_m + 1][_n])
                                    + (_n == 0 ? 1 : dp[step - 1][_m][_n - 1]) + (_n == n - 1 ? 1 : dp[step - 1][_m][_n + 1])) %                                     1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};

int main() {
	return 0;
}

