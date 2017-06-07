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

    int value;
    TreeNode *left, *right;
    TreeNode() : left(nullptr), right(nullptr) {}

};

class Solution {

public:
    TreeNode *root;
    int minmum;

    void constructTree(vector<int> &inord, vector<int> &posord) {
        minmum = 9999;
        root = recursion(inord, posord);
        dfs(root, 0);
        cout << minmum << endl;
    }

    void dfs(TreeNode *p, int ans) {
        if( !p->right && !p->left ) {

            minmum = min(minmum, ans + p->value);
            return ;
        }
        if( p->left)
            dfs(p->left, ans + p->value);
        if( p->right )
            dfs(p->right, ans + p->value);
    }

    TreeNode *recursion(const vector<int> &inord, const vector<int> &posord) {
        TreeNode *p = new TreeNode();
        if( posord.empty() )
            return nullptr;
        p->value = *(posord.end() - 1);
        auto iter = find(inord.begin(), inord.end(), p->value);
        int _right = inord.end() - iter - 1;
        int _left = iter - inord.begin();
        p->left = recursion(vector<int>(inord.begin(), iter), vector<int>(posord.begin(), posord.begin() + _left));
        p->right = recursion(vector<int>(iter + 1, inord.end()), vector<int>(posord.begin() + _left, posord.end() - 1));
        return p;
    }
};

int main() {

    Solution obj;
    vector<int> num1{3,2,1,4,5,7,6};
    vector<int> num2{3,1,2,5,6,7,4};
    obj.constructTree(num1, num2);
	return 0;
}

