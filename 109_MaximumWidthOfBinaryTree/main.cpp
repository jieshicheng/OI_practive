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
	int widthOfBinaryTree(TreeNode* root) {
        vector<pair<int, int>> ans;
        return dfs(root, 1, 0, ans);
    }
    int dfs(TreeNode *p, int cur, int level, vector<pair<int, int>> &ans) {
        if( !p ) {
            return 0;
        }
        if( ans.size() == level ) {
            ans.push_back({cur, cur});
        }
        else {
            ans[level].second = cur;
        }
        return max({ans[level].second - ans[level].first + 1, dfs(p->left, 2 * cur, level + 1, ans), dfs(p->right, 2 * cur + 1, level + 1, ans)});
    }
};

int main() {
	return 0;
}

