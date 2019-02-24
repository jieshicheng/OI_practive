class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        int step = 1;
        for (int i = 1; i <= num; i++) {
            if (i == step) {
                dp[i] = 1;
                step *= 2;
            }
            else if (i % 2 == 0) {
                int temp = i % (step / 2);
                dp[i] = 1 + dp[temp];
            }
            else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp;
    }
};
