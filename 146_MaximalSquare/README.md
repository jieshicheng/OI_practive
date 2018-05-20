LeetCode 221 Maximal Square

Answer:
    我们假设用dp[i][j] = 以i j为右下点的最大正方形的边长。
    那么递推公式就是
    首先判断matrix[i][j]是否为1，如果不是则dp[i][j] = 0;
    然后判断dp[i - 1][j - 1]是否为1，如果不为1，则dp[i][j] = 1;
    然后到了这里我们知道dp[i - 1][j - 1]表示的边长。现在就是要判断
    加上i j这个点后能否构成新的正方形，新的正方形的长度。
    新的正方形多了两条，右边的和下面的，我们用index去索引判断是否这两边
    有1，连续多长。index的最大值自然就是dp[i - 1][j  -1]。
    最后dp[i][j] = index;
    这里需要注意的是，并不是一定要index全部遍历到dp[i - 1][j - 1]才行。
    他们在中途也能构成正方形