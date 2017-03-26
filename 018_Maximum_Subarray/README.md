Question:
    Find the contiguous subarray within an array(containing at least one number)
    which has the largest sum
    Example:
    [-2,1,-3,4,-1,2,1,-5,4] -> [4,-1,2,1] = 6

Solution:
    1.DP  dp[i] = max(dp[i - 1] + nums[i], 0);
    2.Divide and conquer
