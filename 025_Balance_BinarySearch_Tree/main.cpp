#include <iostream>
#include <algorithm>

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
private:
    int deep(TreeNode *ptr)
    {
        if(ptr == nullptr || !ans)
            return 0;
        else
        {
            int leftHeight = deep(ptr->left);
            int rightHeight = deep(ptr->right);
            if(abs(leftHeight - rightHeight) > 1)
                ans = false;
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool ans = true;
public:
    bool isBalanced(TreeNode *root)
    {
        deep(root);
        return ans;
    }
};

int main()
{
	return 0;
}
