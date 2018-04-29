LeetCode 283 Move Zeros

Answer:
    2个指针，i和j。i要一直小于j。i指向最近的0，j指向最近的非0，然后交换。
    交换完再彼此继续往前走。i一直走，直到碰到0，j一直走，直到碰到非0
