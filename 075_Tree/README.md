Question:
    给定一棵树的中序和后序遍历。要你构建出这棵树并求所有叶子节点到根节点中权值和最小的那个叶子节点。
    比如给定
    2 1 3 中序
    2 3 1 后序

    则输出2

    树的结构为
       1
      2 3

    其中2这个叶子节点到根基点的权值和为3.最小


Answer:
    这道题目关键在于构建树。如何根据中序和后序把这棵树构建出来。等树构建出来了，只需要一个简单的DFS
    便可以求出最小的路径。

    对于构建这棵树我们可以递归的来做。观察后序遍历，它的最后一个元素就是根节点。
    然后我们在中序遍历中找到它。这样它左边的就是根的左子树长度为left，右边的就是根的右子树长度为right。
    然后后序遍历的前Left个元素也是根的左子树，后right个元素是根的右子树。然后就递归的下去求。只需把左边的中序和后序
    作为新参数传递下去即可。
