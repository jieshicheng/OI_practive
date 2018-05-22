LeetCode 312 Burst Balloons

Answer:

    想了好久都没想出怎么高效的解法，看了discuss，真的是不禁感叹自己菜。。。。。

    反向思维是第一位，用dp[left][right]来表示边界为left和right的区间的解。

    在一开始看到left * i * right的形式时还不理解，但是从反向思考的角度来思考，真的是完美的关系。

    首先在拿最后一个气球时，left与right保障指向1，而拿倒数第二个气球的时候，left与right中一个必然指向

    倒数第一个气球，另一个指向1，同理，拿第三个气球的时候，left与right要么中有一个是气球，另一个是1，要么两个都是气球。

    这种逆推边界完美的模拟了正推的情况，真的unimaginable。
