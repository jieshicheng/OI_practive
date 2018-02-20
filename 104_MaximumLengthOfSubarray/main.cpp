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
    int findLength(const vector<int>& A, const vector<int>& B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int ans = 0;
        for( int i = 1; i <= A.size(); ++i ) {
            for( int j = 1; j <= B.size(); ++j ) {
                if( A[i - 1] == B[j - 1] ) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }	
};

int main() {
	Solution solv;
    cout << solv.findLength({1,2,3,2,1}, {3,2,1,4,7}) << endl;
    return 0;
    
}

