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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recur(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    TreeNode *recur(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if( inBegin == inEnd )
            return nullptr;
        TreeNode *node = new TreeNode(preorder[preBegin]);
        const auto &iter = find(inorder.begin() + inBegin, inorder.begin() + inEnd, preorder[preBegin]);
        int distance = iter - (inorder.begin() + inBegin);
        node->left = recur(preorder, inorder, preBegin + 1, preBegin + distance + 1, inBegin, inBegin + distance);
        node->right = recur(preorder, inorder, preBegin + distance + 1, preEnd, inBegin + distance + 1, inEnd);
        return node;
    }
};

int main() {
	return 0;
}

