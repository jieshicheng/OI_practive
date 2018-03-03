#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}


class Solution {
public:
	int rob(TreeNode *root) {
        vector<int> ans = dp(root);
        return max(ans[0], ans[1]);
    }

    vector<int> dp(TreeNode *p) {
        if( p == nullptr )
            return {0, 0};
        vector<int> left = dp(p.left);
        vector<int> right = dp(p.right);
        vector<int> ans{0, 0};
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = p.val + left[0] + right[0];
        return ans;
    }
};

int main() {
	return 0;
}

