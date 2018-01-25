LeetCode 198 House Robber

Answer:
    一个简单的dp题目。这道题目我是通过740 Delete and Earn关联过来的
    两者确实有挺大相似点的。
    这道题目中关键在于选与不选。我们有
    skipi：表示跳过第i个点
    takei：表示选取第i个点
    skip：表示跳过i-1个节点，所偷到的钱
    take：表示拿到i-1个节点，所偷到的钱
    递推公式如代码所示。
    同时740 Delete and Earn非常推荐大家做一做
