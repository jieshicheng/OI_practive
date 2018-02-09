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
	int countSubstrings(string s) {
        vector<int> dp(s.size(), 1);
        for( int i = 1; i != s.size(); ++i ) {
            dp[i] += dp[i - 1];
            for( int length = 2; length <= i + 1; ++length ) {
                int begin = i - length + 1;
                int end = i;
                while( begin < end && s[begin] == s[end] ) {
                    begin++;
                    end--;
                }
                if( begin == end || begin - end == 1 )
                    dp[i]++;
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
	return 0;
}

