#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
};


typedef pair<int , TreeNode *> pair_;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if( !root )
            return 0;
        queue<pair_> que;
        que.push(pair_(1 , root));
        TreeNode *p;
        int deep = 0;
        while( !que.empty() )
        {
            p = que.front().second;
            deep = que.front().first;
            que.pop();
            if( p->left)
                que.push(pair_(deep + 1 , p->left));
            if( p->right )
                que.push(pair_(deep + 1 , p->right));
        }
        return deep;
    }
};

int main()
{
    TreeNode *p = new TreeNode(5);
    p->left = new TreeNode(4);
    Solution obj;
    cout<<obj.maxDepth(p)<<endl;
    delete p->left;
    delete p;
    return 0;
}
