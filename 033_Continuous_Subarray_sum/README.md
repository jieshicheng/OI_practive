问题：
    给定一个非负数的整数数组nums，一个整数k。问是否这个数组中存在长度至少为2的连续序列和为k的整数倍

    例子：
    [23, 2, 4, 6, 7] k = 6
    true
    because [2, 4] = 6
            [2, 4, 6] = 12 = 2 * 6

    [23, 2, 6, 4, 7] k = 6
    true
    because [23, 2, 6, 4, 7] = 42 = 6 * 7

思路：
    DP类型题目
    我们用一个map来保存数组的前i个数字的和模k的结果和i。
    给定j > i
    如果(sum[j] % k == sum[i] % k && i - j > 1),那么就为true
    
