Question:
    Given a binary tree , find its maximum depth

Solution:
    Two ways.
    1.Seacher binary tree use BFS , or call it's level order traversal
        That is my code.


    2.using recursion.
        it's an easy way to understand and write . because the maximum depth is root's left tree plus one or right tree plus one . and recursion so on
        
        code:
        
        int maxDepth(TreeNode *root)
        {
            if( !root->left && !root->right )
                return 1;
            else
                return std::max(maxDepth(p->left) + 1 , maxDepth(p->right) + 1);
        }
