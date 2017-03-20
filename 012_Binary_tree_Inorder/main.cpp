#include <iostream>
#include <vector>
#include <stack>

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
	void Inorder(TreeNode *p, vector<int> &vec)
	{
		if(!p)
			return ;
		Inorder(p->left, vec);
		vec.push_back(p->val);
		Inorder(p->right, vec);
	}

	vector<int> inorderTraversal(TreeNode *root)
	{	
		vecot<int> vec;
		Inorder(root, vec);
		return vec;
	}
};

int main()
{
	return 0;
}
