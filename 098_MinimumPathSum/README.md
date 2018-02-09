LeetCode 64 Minimum Path Sum

Answer:
    简单的dp公式
    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
    注意边界情况
