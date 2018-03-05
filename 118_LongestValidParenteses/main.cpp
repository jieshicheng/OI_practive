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
    int longestValidParentheses(string s) {
        if( s.size() == 0 )
            return 0;
        stack<int> stk;
        for( int i = 0; i != s.size(); ++i ) {
            if( s[i] == '(' ) {
                stk.push(i);
            }
            else {
                if( stk.empty() )
                    stk.push(i);
                else if( s[stk.top()] == '(' ) {
                    stk.pop();
                }
                else {
                    stk.push(i);
                }
            }
        }
        int end = s.size(), begin = 0, ans = 0;
        if( stk.empty() )
            return end - begin;
        while( !stk.empty() ) {
            begin = stk.top();
            stk.pop();
            ans = max(ans, end - begin - 1);
            end = begin;
        }
        ans = max(ans, begin);
        return ans;
    }
};

int main() {
	return 0;
}

