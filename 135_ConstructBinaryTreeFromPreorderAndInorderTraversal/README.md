LeetCode 105 Construct Binary Tree From Preorder And Inorder Traversal

Answer:
    这个是数据结构的经典题。运用递归的思想
    preBegin preEnd表示preorder的头尾
    inBegin inEnd表示inorder的头尾
    首先preBegin的第一个元素就是root节点，然后我们通过这个节点
    去inorder索引，然后它左边的就是左子树，右边的就是右子树
    然后更改递归的参数头尾，就可以递归下去。需要注意出口条件，就是
    头尾指向相等的地方，代表没有元素了。则返回nullptr
