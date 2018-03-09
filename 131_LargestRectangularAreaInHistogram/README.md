LeetCode 84 Largest Rectangle in Histogram

Answer:
    一开始想简单了，暴力解的O（n * m）m为heights中的最大值
    结果超时，后面无论怎么想都没做出来这道题目，看的解析才知道自己一直
    没碰到答案的边，一直在想着用dp怎么优化去了。。。
    解析给了两种解，一种是分治思想O（nlogn），一种是用stack O（n）
        先讲分治思想，就是寻求heights中最小的值下标index，然后可行的解就是3中
    1.begin -> index - 1的最大值
    2.index + 1 -> end的最大值
    3.heights[index] * length
    这三个中的最大值。然后就是递归的解决问题
        再说stack如何做，首先这个解法很奇妙，理解了但是还是觉得不知道这个
    做法是如何推演出来的，不知道属于哪一种思想。
    首先就是说stack用来保存下标，然后遍历heights，
    当heights[i] >= heights[stk.top()]
        的时候才将i入stack。也就是说stack中保存了heights中高度的升序下标。
    如果不大于等于，那么就计算以heights[stk.top()]为高度的矩阵的面积
    那么宽度怎么求呢？这里就是巧妙点了，宽度就是i - stk.top()（注意已经pop过） - 1
    为什么宽度是这个，大家通过画图可以更直观的了解。
