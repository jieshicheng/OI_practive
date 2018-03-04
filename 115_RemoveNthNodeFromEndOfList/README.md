LeetCode 19 Remove Nth Node From End Of List

Answer:
    这道题要求一次遍历做完。
    用两个指针，first和second。其中second比first快n步。那么一旦second等于null
    也就意味到了list的end。那么只要删除first就行。
    然后在其中加了一些边界条件的判断，比如删除头尾的情况
