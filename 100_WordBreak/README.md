LeetCode 139 Word Break

Anwer:
    dp[i] = 当问题为i结尾的字符串的题目答案
    因为这道题目中的要求，字符串s要能够被划分为wordDict中的一个或多个
    字符串，可以是wordDict中重复的组成。但是s中被划分开的单词不能重复
    也就是“aaaaaaa” ["aaaa", "aa"]中，答案是false的。
    因为s不能划分为有重叠区域的，所以此s是false的。
    最后因为这个特性，递推公式也是因此有限制，
    j从0开始遍历以i结尾的所有子串，只有当dp[j]为true，s(j, i)的字符串还能在
    wordDict中找到时，dp[i]才能为true
