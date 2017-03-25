#include <iostream>

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int value) : val(value), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)    //ways one
    {
        if( !root )
            return ;
        if(root->right && root->left)
        {
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
    }

    void No_Recursion(TreeLinkNode *root)      //ways two
    {
        while(root)
        {
            if( !root->left )
                return ;
            auto cur = root;
            root = root->left;
            
            if( !cur->next )
                root->next = cur->right;
            else
            {
                while(cur->next)
                {
                    cur->left->next = cur->right;
                    cur->right->next = cur->next->left;
                    cur->next->left->next = cur->next->right;
                    
                    cur = cur->next;
                }
            }
        }
    }
};

int main()
{
	return 0;
}
