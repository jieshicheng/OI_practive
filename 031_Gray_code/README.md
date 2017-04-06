Question:
    The gray code is a binary numeral system where two successive values
        differ in only one bit
    Given a non-negative integer n representing the total number of bits
        in the code.
    A gray code sequence must begin with 0
    Example:
        2 => [0,1,3,2]

Solution:
    对于每一个二进制表示的整数i，都可以通过i / 2 ^ i 来将底层位表示转换成gray code。
