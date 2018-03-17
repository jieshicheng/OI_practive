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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recur1(root, p, q);
    }
    
    TreeNode *recur1(TreeNode *root, TreeNode *p, TreeNode *q) {
        if( !root )
            return nullptr;
        if( root == p || root == q )
            return root;
        TreeNode *left = recur1(root->left, p, q);
        TreeNode *right = recur1(root->right, p, q);
        if( left && right )
            return root;
        if( left )
            return left;
        else if( right )
            return right;
        return nullptr;
    }	
};

int main() {
	return 0;
}

