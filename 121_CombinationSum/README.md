LeetCode 39 Combination Sum

Answer:
    直接暴力dfs即可。从第0个元素开始，我们通过target / candidates[i]来得到
    最大可以选择多少个i元素，然后从选择0个直到选择targe / candidates[i]个
    剩余的target即为target - candidates[i] * times
