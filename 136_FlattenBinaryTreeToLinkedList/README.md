LeetCode 114 Flatten Binary Tree To Linked List

Answer:
    没什么算法可讲，就是编程能力。我的做法是递归实现
    将左子树折叠完毕后会返回这个左子树的最右下角的指针
    然后将这个指针的right指向当前节点的right
    然后当前节点的right等于left，left等于nullptr，这样
    便完成了对左子树的折叠操作，这时候再通过前面保存的节点的右子树指针（现在的right并不是真正的right，是折叠过来的left，所以说原先保存的right）
    对右子树进行折叠操作。
    这种递归的出口就是只有一个节点的时候，那么返回这个节点本身即可
