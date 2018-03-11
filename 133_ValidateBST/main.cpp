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
	bool isValidBST(TreeNode* root) {
        vector<int> vec;
        dfs(root, vec);
        if( vec.size() <= 1 )
            return true;
        for( int i = 0; i < vec.size() - 1; ++i ) {
            if( vec[i] >= vec[i + 1] )
                return false;
        }
        return true;
    }
    
    void dfs(TreeNode *node, vector<int> &vec) {
        if( !node ) {
            return ;
        }
        dfs(node->left, vec);
        vec.push_back(node->val);
        dfs(node->right, vec);
        return ;
    }
};

int main() {
	return 0;
}

