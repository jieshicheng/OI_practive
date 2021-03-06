问题：
    给一个整数序对的数组，寻找你可以删除的最少序对数量以保证剩下的部分没有重叠
    你可以假设序对的第二个数字总比第一个数字大
    边界重叠是可以的，比如[1,2],[2,3]边界2重叠了，这是可以的
    例子：
        [[1,2], [2,3], [3,4], [1,3]]
        output:
            1
        because: [1,3]与前面的有重叠部分，删除后剩下的就不重叠了

        [[1,2], [2,3]]
        output:
            0
        because: 没有重叠的部分，不用删除

思路：
    经典的贪婪题目。我们就整个序对，针对序对的第二个元素按照从小到大来排序
    排好序后遍历它，用bord来代表目前又序对构成的数轴上最大的值，然后就新的
    序对，判断新序对的第一个元素是否小于bord，如果小于则代表必定有重叠，那么答案++，如果不小于的话，那么新的bord=序对的第二个元素。这样遍历完就得到了我们需要删除的序对的个数
    这里我们采用的贪婪思想是：每次选择pair.second的最小的那个序对，这样在数轴上我们是从小到大一步步过去的，所以必然保证了是全局的最优解
