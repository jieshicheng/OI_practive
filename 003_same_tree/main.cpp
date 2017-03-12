#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p , TreeNode *q)
    {
        if(p == nullptr || q == nullptr)
            return q == p;
        if(p->val == q->val)
            return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
        else
            return false;
    }
};

int main()
{
    TreeNode *p = new TreeNode(4);
    TreeNode *q = nullptr;
    Solution obj;
    cout<<obj.isSameTree(q , p)<<endl;
    return 0;
}
