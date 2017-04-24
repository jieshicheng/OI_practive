问题：
    给定一个整数数组和k，求这个数组的第k大元素
    例子：
    [3, 2, 1, 5, 6, 4] k = 2
    5

思路：
    这个题目算法导论里面讲分治思想的时候说到过，这道题目其实就是quick sort的一个非排序版本
    qSort运用分治的思想，把大的待排序集合划分为小的集合，然后再将小的合并起来，然后在qSort的每次
    递归的时候它选的划分点虽然两边的顺序还不确定，但划分点这个时候已经是在它正确的位置了
    什么意思呢，划分点左边的元素比划分点小，右边的比划分点大，所以划分点就是这整个数组的第k大元素了
    我们要寻找第k大元素，就只需要用到qSort的一个简化版本，时间复杂度o(log n)