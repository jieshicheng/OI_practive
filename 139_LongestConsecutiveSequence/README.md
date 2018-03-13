LeetCode 128 Longest Consecutive Sequence

Answer:
    很精妙的想法，就是用hashmap存储所有节点的值以及它能组成的最长序列
    代码比较难懂的因该是mp[nums[i] - left] = length mp[nums[i] + right] = length
    这两行的左右是在更新新节点的时候，要更新它所组成的序列里的所有节点的最长序列值
    这也是它的有意思的地方，它只更新边界，但是其实每次一步步扩张序列的长度
    也就保证了整个序列都是变成了正确的值
