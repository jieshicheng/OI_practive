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
	void flatten(TreeNode* root) {
        if( !root )
            return ;
        else
            recur(root);
    }
    
    TreeNode *recur(TreeNode *node) {
        if( !node->left && !node->right )
            return node;
        TreeNode *rightNode = node->right;
        TreeNode *temp;
        if( node->left ) {
            temp = recur(node->left);
            temp->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        if( rightNode )
            return recur(rightNode);
        else 
            return temp;
    }
};

int main() {
	return 0;
}

