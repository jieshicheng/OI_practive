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
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if( row == 0 )
            return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int ans = 0;
        for( int i = 0; i != row; ++i ) {
            for( int j = 0; j != col; ++j ) {
                if( i == 0 || j == 0 ) {
                    if( matrix[i][j] == '1' )
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                    ans = max(ans, dp[i][j]);
                    continue;
                }
                if( matrix[i][j] == '1' ) {
                    if( matrix[i - 1][j - 1] != '1' ) 
                        dp[i][j] = 1;
                    else {
                        int length = dp[i - 1][j - 1];
                        int index;
                        for( index = 1; index <= length; ++index) {
                            if( matrix[i - index][j] == '1' && matrix[i][j - index] =='1' )
                                continue;
                            else 
                                break;
                        }
                        dp[i][j] = index;
                    }
                }
                else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }	
};

int main() {
	return 0;
}

