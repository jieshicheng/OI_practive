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
    int numDecodings(string s) {
        if( s.empty() )
            return 0;
        vector<int> dp(s.size(), 0);
        if( s[0] == '0' )
            return 0;
        if( s.size() == 1 )
            return 1;
        dp[0] = 1;
        if( s.size() >= 2 ) {
            if( s[1] == '0' ) {
                if( s[0] > '2' )
                    return 0;
                else
                    dp[1] = 1;
            }   
            else if( s[0] == '1' )
                dp[1] = 2;
            else if( s[0] == '2' && s[1] <= '6' )
                dp[1] = 2;
            else
                dp[1] = 1;
        }
        
        for( int i = 2; i != s.size(); ++i ) {
            if( s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0') )
                return 0;
            if( s[i] == '0' )
                dp[i] = dp[i - 2];
            else if( s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6') ) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        } 
        return dp[s.size() - 1];
    }
};

int main() {
    Solution solv;
    cout << solv.numDecodings("11234") << endl;
    return 0;
}

