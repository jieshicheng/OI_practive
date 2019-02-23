question:

    given an array of integers. Each element in arry appears twice. except two element that only appears once.

    You should find the two special elements whit linear complexity.

solution:

    We already know that by using xor can find out the value that appears in array. only if the elements in array appears twice but one element appears just once. so how do we apply such ideas to this subject?

    Let's assume the result is A and B.

    The point is when you pust all the elements together with xor operator, you actually get the value of A xor B. Such as 000101, look at the bits whose value equal 1, that means we can divided it to two arrays according bit whose value equals 1. And apply xor to the sub array, the final value of two array is what we want.
