#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    bool have_value;
    int value;
    TreeNode *left, *right;
    TreeNode() : have_value(false), left(nullptr), right(nullptr) {}
};

class Solution {

public:
    TreeNode *root;

    bool handler_node(int value, const string &str) {
        TreeNode *node = root;
        if( str[0] == ')' ) {
            if( node->have_value == true )
                return false;
            node->value = value;
            node->have_value = true;
            return true;
        }
        for(int i = 0; i != str.size(); ++i) {
            if( str[i] == ')' ) {
                if( node->have_value == true )
                    return false;
                node->value = value;
                node->have_value = true;
            }else if( str[i] == 'L') {
                if( !node->left )
                    node->left = new TreeNode();
                node = node->left;
            }else {
                if( !node->right )
                    node->right = new TreeNode();
                node = node->right;
            }
        }
        return true;
    }

    void accessLevel(vector<int> &ans) {
        if( root->have_value == false )
            return ;
        queue<TreeNode *> que;
        que.push(root);
        while( !que.empty() ) {
            auto temp = que.front();
            que.pop();
            ans.push_back(temp->value);
            if( temp->left )
                que.push(temp->left);
            if( temp->right )
                que.push(temp->right);
        }
        return ;
    }

    vector<int> traLevel() {
        root = new TreeNode();
        string s;
        while( cin >> s && s[1] != ')' ) {
            istringstream buf(&s[1]);
            int value;
            string pos;
            buf >> value >> pos;
            if( handler_node(value, &pos[1]) == false )
                return vector<int>{-1};
        }
        if( root->have_value == false )
            return vector<int>{-1};
        vector<int> ans;
        accessLevel(ans);
        return ans;
    }
};

int main() {
    Solution obj;
    auto temp = obj.traLevel();
    for( const auto &r : temp )
        cout << r << " ";
    cout << endl;
    return 0;
}

