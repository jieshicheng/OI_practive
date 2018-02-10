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
    bool wordBreak(string s, const vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for( int i = 1; i <= s.size(); ++i ) {
            for( int j = 0; j != i; ++j ) {
                if( !dp[j] )
                    continue;
                string temp = s.substr(j, i - j);
                cout << temp << ' ';
                for( int iter = 0; iter != wordDict.size(); ++iter ) {
                    if( temp == wordDict[iter] ) {
                        dp[i] = true;
                        break;
                    }
                }
                if( dp[i] )
                    break;
            }
            cout << dp[i] << endl;
        }
        return dp[s.size()];
    }
};

int main() {
	Solution solv;
    cout << solv.wordBreak("aaaaaaa", vector<string>{"aaaa", "aa"}) << endl;
    return 0;
}

