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
    TreeNode* invertTree(TreeNode* root) {
        recur(root);
        return root;
    }
    
    void recur(TreeNode *node) {
        if( node == nullptr ) {
            return ;
        }
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        recur(node->left);
        recur(node->right);
    }	
};

int main() {
	return 0;
}

