LeetCode 76 Minimum Window Substring

Answer:
    string类型题目一直是弱点。这道题目没想出来，一开始想到了two pointer
    但是却是想用来从头尾遍历，也想到了hash来保存下标。
    这道题的关键点都想到了，但是都用错了。绝望。。。。
    正确的用法是two pointer用来定位window的两边。
    start表示起点，end表示终点。hash或者其他的来保存你找到的字符。其实
    数组之类的保存也可以，反正只要你能存储下正确找到的字符即可。
    然后一旦一开始end找到了，也就是第一个窗口找到了，end就先别动，start往
    前动，直到路过一个我们需要的字符，这样，start-end组成的窗口就少了一个字符
    那样我们再挪动end去找这个我们丢失的字符。这样子window就是一顿一顿的往
    前方移动，移动过程中保存下最短的区间即可。
    哎哎哎啊，这么简单都没想到
