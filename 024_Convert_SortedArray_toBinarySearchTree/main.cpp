#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *rightl
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *construct(vector<int> &nums, int _begin, int _end)
    {
        if(_begin == _end)
            return new TreeNode(nums[_end]);
        if(_end - _begin == 1)
        {
            TreeNode *node = new TreeNode(nums[_end]);
            node->left = new TreeNode(nums[_begin]);
            return node;
        }
        int med = _begin + (_end - _begin) / 2;
        TreeNode *node = new TreeNode(nums[med]);
        node->left = construct(nums, _begin, med - 1);
        node->right = construct(nums, med + 1, _end);
        return node;
    }


    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int length = nums.size();
        if(length == 0)
            return nullptr;
        else
            return construct(nums, 0, nums.size() - 1);
    }
};

int main()
{
	return 0;
}
