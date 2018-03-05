LeetCode 32 Longest Valid Parenteses

Answer:
    最原始的思路：O（n * n）
    对s中的第i字符，从i开始遍历到end。然后用stack判断valid parenteses。
    不过time out了
    看了discuss后才知道关键所在。一直用stack来保存的字符
    ‘（’ ‘）’但是其实这两个字符是不用保存的，根据stack的进出规则其实
    就包含了字符的信息。既然隐含的知道了字符的信息，那么就可以保存额外的
    信息，比如他们的下标。如果我们用stack保存下标，在一次遍历完毕后，
    该匹配的都匹配了，stack中只留下了不能匹配的字符的下标。
    那么这些下标所构成的许多个区间就是valid parenteses了。所以我们
    只要取这些区间中最大的那个即可
    
