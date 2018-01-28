LeetCode 309 Best Time to Buy and Sell Stock with CoolDown

Answer:
    这个dp问题，非常完美的诠释了state这个概念。
    首先要推出dp公式，则一定要确定好状态。将所需要的状态都保存
    才能得到dp公式。
    这里的递推公式是：
    buy[i] = max(buy[i - 1], sell[i - 2] - prices[i])
    sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])
    其实这个递推公式不难想到，关键是想到状态数组。然后根据状态数组就可以
    根据题目条件推出这个公式了
