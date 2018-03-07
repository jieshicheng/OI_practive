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
	int minDistance(string word1, string word2) {
        if( word1.empty() )
            return word2.size();
        if( word2.empty() )
            return word1.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for( int j = 0; j <= word2.size(); ++j )
            dp[0][j] = j;
        for( int i = 0; i <= word1.size(); ++i )
            dp[i][0] = i;
        for( int i = 1; i <= word1.size(); ++i ) {
            for( int j = 1; j <= word2.size(); ++j ) {
                if( word1[i - 1] == word2[j - 1] ) {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1] + 1, dp[i - 1][j] + 1});
                }
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
	return 0;
}

