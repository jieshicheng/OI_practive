LeetCode question No.90 Subsets II

求子集，我用的是位表示法。有N个元素，那么每个元素选与不选就分别为0和1
然后这个01数组就组成了一个整数。整数最大为全1，最小为全0.
用一个循环遍历这个区间，然后对于每个数字，求它的二进制表示法，然后就是一个子集
问题是里面会出现重复值，所以我把所有子集排序，然后判断数组是否相等