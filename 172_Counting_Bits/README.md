question:

    338. Counting Bits

answer:

    result array of number n. The answer of input number is n.

    value of n. The number of 1's in n's binary representation.

    It's pretty insteresting. Let's assume that you already know the result arry of number n - 1. Now you want to know the result array of number n. The first n - 1 elements in array are samed. So we just try to figure out how to calculate the value of n. There are three possibilities for the value of n.
    
    1.n is a power of 2:

        it equals 1.

    2.n is odd

        it equals the value of n - 1 plus 1.

    3.n is even

        this situation has a little complexity. for example, the n is 24, The number n - 1's binary representation is 0010111. when plus 1, a continuous carry occurs. but we already know the value of any number less than n. So we divided 24 to two part. one's the bit that equals 1 and on the far left. anthoer's the remaining numbers. In this case equals 0010000 and 0000111. so value of n equals 1 plus value of 0000111, and 0000111 we already known.
        
        

