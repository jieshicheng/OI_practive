LeetCode 152 Maximum Product Subarrya

Answer:
    这道题虽然没明说需要保存的状态，但因为乘法的特殊性，所以我们需要
    保存最大值和最小值。这样在在面对负数的时候，可以直接反转得到最大值和最小值
    递推公式
    nums[i] >= 0
        large[i] = max(large[i - 1] * nums[i], nums[i])
        small[i] = min(small[i - 1] * nums[i], nums[i])
    nums[i] < 0
        large[i] = max(small[i - 1] * nums[i], nums[i])
        small[i] = min(large[i - 1] * nums[i], nums[i])
    因为状态只依赖上一个状态，所以不需要数组来保存。直接两个变量滚动保存就行
