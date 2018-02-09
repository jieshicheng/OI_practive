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
	int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0; i != m; ++i ) {
            for( int j = 0; j != n; ++j ) {
                if( i == 0 && j ==0 )
                    continue;
                else if( i == 0 )
                    dp[i][j] += dp[i][j - 1];
                else if( j == 0 )
                    dp[i][j] += dp[i - 1][j];
                else
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
	return 0;
}

