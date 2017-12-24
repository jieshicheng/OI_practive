Question:
    给定一颗二叉树，每个节点有一个水平位置。左节点在根的左边一个单位，右节点在根右边一个单位。
    要你输出这颗二叉树的在同一列的权值和。输入数据是按照先序遍历的方式递归的输入,-1代表空。
    比如二叉树结构如下
       5
     7   3
       6
    输入结构为
    5 7 -1 6 -1 -1 3 -1 -1
    输出应该为
    7 11 3
    分别是第一列，第二列，第三列的值

Answer:
    一开始用的结构体。在想同一列怎么处理。后面看了解析才恍悟
    这里用数组来做更好。在题目中一开始提到了水平位置。且左子树和右子树分别是一个单位的差别。
    这种就是提示用数组来表示树。
    我们可以先开一个足够大的数组，数组的中点就是根。往左边走，左子数。右边走右子树。
    对应的权值也直接放到相应的下标中去。这样输出的时候也直接顺序输出就行了。
    非常nice的思路。长见识了
