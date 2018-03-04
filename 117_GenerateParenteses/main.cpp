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
	vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, 0, 0, "", n);
        return ans;
    }
    void dfs(vector<string> &ans, int left, int right, string s, int n) {
        if( left < right )
            return ;
        if( left == n && right == n ) {
            ans.push_back(s);
            return ;
        }
        if( left < n )
            dfs(ans, left + 1, right, s + "(", n);
        if( right < n && right < left )
            dfs(ans, left, right + 1, s + ")", n);
    }
};

int main() {
	Solution solv;
    auto iter = solv.generateParenthesis(3);
    for( auto r : iter )
        cout << r << endl;
    return 0;
}

