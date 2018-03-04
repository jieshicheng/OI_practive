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
	bool isValid(string s) {
        stack<char> stk;
        if( s.size() == 1 )
            return false;
        for( int i = 0; i != s.size(); ++i ) {
            if( s[i] == '{' || s[i] == '(' || s[i] == '[' ) {
                stk.push(s[i]);
                continue;
            }
            else {
                if( stk.empty() )
                    return false;
                char temp = stk.top();
                stk.pop();
                if( s[i] == '}' && temp == '{' )
                    continue;
                else if( s[i] == ')' && temp == '(' )
                    continue;
                else if( s[i] == ']' && temp == '[' )
                    continue;
                else
                    return false;
            }
        }
        if( stk.empty() )
            return true;
        else
            return false;
    }
};

int main() {
	return 0;
}

