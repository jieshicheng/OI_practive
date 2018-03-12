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
	int maxPathSum(TreeNode* root) {
        int maxVal = -999999;
        pair<int, int> ans = recur(root, maxVal);
        return ans.second == 0 ? maxVal : ans.second;
    }
    
    pair<int, int> recur(TreeNode *node, int &maxVal) {
        if( !node )
            return {0, 0};
        maxVal = max(maxVal, node->val);
        pair<int, int> left = recur(node->left, maxVal);
        pair<int, int> right = recur(node->right, maxVal);
        pair<int, int> root;
        root.first = max({left.first + node->val, right.first + node->val, node->val});
        root.second = max({left.second, right.second, node->val, left.first + node->val + right.first, root.first});
        return root;
    }
};

int main() {
	return 0;
}

