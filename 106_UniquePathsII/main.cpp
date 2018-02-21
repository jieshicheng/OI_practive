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
	int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid.empty() )
            return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,  vector<int>(col, 0));   
        dp[0][0] = 1;
        for( int i = 0; i != row; ++i ) {
            for( int j = 0; j != col; ++j ) {
                if( obstacleGrid[i][j] == 1 ) {
                    dp[i][j] = 0;
                    continue;
                }
                if( i - 1 >= 0 )
                    dp[i][j] += dp[i - 1][j];
                if( j - 1 >= 0 )
                    dp[i][j] += dp[i][j - 1];
            }
        } 
        return dp[row - 1][col - 1];
    }
};

int main() {
	Solution solv;
    cout << solv.uniquePathsWithObstacles({{0, 0}, {0, 0}}) << endl;
    return 0;
}

