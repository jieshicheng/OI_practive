问题：
    给定一个32位大小的整数，可以随便改变这个整数的各个位的位置，求该整数的下一个大于它的数字，若无则为-1
    例子：
    12
    21
    because：12改变顺序为21，比12大

    21
    -1
    because：不存在变顺序后比21大的

    32415
    32451
    because：同上

思路：
    将整数转换成相应字符串，然后从最小的个位数开始遍历，寻找比这一位右边的最小数，然后交换他们的位置。最后将右边的按从小到大排序即可