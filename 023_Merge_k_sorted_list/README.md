Question:
    Merge k sorted linked list and return it as one sorted list,
    Analyze and describe its complexity

Solution:
    it can divide smaller question.k => k / 2  divide two question. Merge
    k / 2 sorted linked list, after merge two.
    这道题的简化版本要我们合并两个链表，在这个版本中，我们通过分治思想，把k个问题分化成1->k/2和k/2->k，一直这样分化下去，直到只剩两个或者一个，这样我们直接用上一问的方法合并他们，并返回。
    时间复杂的O(nlongk)
