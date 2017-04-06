#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    bool compare_(TreeNode *lhs, TreeNode *rhs)
    {
        if(!lhs && !rhs)
            return true;
        if(lhs && rhs)
        {
            if(rhs->val == lhs->val)
                return compare_(lhs->left,rhs->right) && compare_(lhs->right, rhs->left);
        }
        return false;
    }


	bool isSymmetric(TreeNode *root)
    {
        if(!root)
            return true;
        else
            return compare_(root->left, root->right);
    }
};

int main()
{
	return 0;
}

