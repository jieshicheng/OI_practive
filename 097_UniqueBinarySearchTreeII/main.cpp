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
	vector<TreeNode*> generateTrees(int n) {
        if( !n )
            return vector<TreeNode*>();
        return getTree(1, n);
    }
    
    vector<TreeNode*> getTree(int begin, int end) {
        vector<TreeNode*> ans;
        if( begin > end ) {
            ans.push_back(nullptr);
            return ans;
        }
        if( begin == end ) {
            ans.push_back(new TreeNode(end));
            return ans;
        }
        for( int i = begin; i <= end; ++i ) {
            vector<TreeNode*> left = getTree(begin, i - 1);
            vector<TreeNode*> right = getTree(i + 1, end);
            
            for( auto &l : left ) {
                for( auto &r : right ) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;           
    }
};

int main() {
	return 0;
}

