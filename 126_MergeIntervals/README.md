LeetCode 56 Merge Intervals

Answer:
    做过很多次的经典题目。贪心题目
    关键点是排序给定的intervals。贪心原则就是按照start从小到达排序。如果
    start相同，就按照end从小到大排序
    然后得到了排序后的intervals，就可以开始遍历合并了，用temp表示当前正在
    准备合并的目标interval。
    if intervals[i].start <= temp.end就
        代表两者有重叠，则自然可以拼接到一起，所以temp.end = intervals[i].end
    else
        代表两者无重叠，所以现在的temp就是一个成型的interval，加入ans即可。
        新的temp自然等于intervals[i]
