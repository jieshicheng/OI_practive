LeetCode 304 Range Sum Query

Answer:
    要求是常量时间求出来，那么必然需要对martix做一定的预处理
    我们把martix[i][j]定义为从（0，0）到（x，y）矩阵的数字和。
    那么从给定的（x1，y1）到（x2，y2）的值为
    martix[x2][y2] - martix[x1 - 1][y2] - martix[x2][y1 - 1] + martix[x1 - 1][y2 - 1]
    这样就是常量时间算出来。
    对于martix的预处理
    martix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1]
