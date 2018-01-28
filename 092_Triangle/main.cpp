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
    int minimumTotal(const vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        if( triangle.size() == 1 )
            return triangle[0][0];
        for( int i = 1; i != triangle.size(); ++i ) {
            for( int j = 0; j != triangle[i].size(); ++j ) {
                if( j - 1 < 0 )
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if( j == triangle[i].size() - 1 )
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
        return *min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    }
};

int main() {
	Solution solv;
    cout << solv.minimumTotal({{2,}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}) << endl;
    return 0;
}

