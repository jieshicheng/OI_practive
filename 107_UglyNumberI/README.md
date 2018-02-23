LeetCode 263 Ugly Number I

Answer:
    给定num，如果它是丑数，则它一定可以被2 3 5一直整除。
    那么我们用num除以2 3 4，如果除的尽，则将值再赋予num，若除不尽
    则不是丑数
