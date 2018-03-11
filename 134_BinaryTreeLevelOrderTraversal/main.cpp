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
	vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root )
            return ans;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        while( !que.empty() ) {
            pair<TreeNode *, int> temp = que.front();
            que.pop();
            if( temp.second >= ans.size() )
                ans.push_back(vector<int>());
            ans[temp.second].push_back(temp.first->val);
            if( temp.first->left )
                que.push({temp.first->left, temp.second + 1});
            if( temp.first->right )
                que.push({temp.first->right, temp.second + 1});
        }
        return ans;
    }
};

int main() {
	return 0;
}

