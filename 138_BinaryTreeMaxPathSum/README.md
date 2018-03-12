LeetCode 124 Binary Tree Maximum Path Sum

Answer:
    DP题目。并且搭配Tree。就使得这种题目简单了，因为Tree完全适配递归
    然后递归又适配DP的递推，所以递推公式也很容易想出来，这里的递推公式就是
    假设我们用pair<int, int> 第一个表示以当前节点为结尾，第二个表示我们需要的最大值
    那么如何递推呢。首先假设我们知道left和right的pair<int, int>数据
    那么根节点node的pair<int, int>这样递推
    first：等于以左子树根节点为结尾的   left.first + node->val
                                        right.first + node->val
                                        node->val以上三者的最大值
            这样才保障了是以node为结尾节点
    second：是指我们需要的答案，也就是node节点为树的解。它等于
                                        left.second
                                        right.second
                                        root.first
                                        left.first + right.first + node->val
                                        四者中的一个
    那么递归的终止条件自然就是空节点，其pair<>数据为0，0
