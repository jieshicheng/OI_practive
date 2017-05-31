#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int check(vector<int> &nums, vector<int> &dp, int index, int k) {
        int up = nums[index - 1] + k;
        int down= nums[index - 1] - k;
        int ans = 0;
        int last = 0;
        for(int i = 1; i != index; ++i) {
            if(nums[i - 1] == up || nums[i - 1] == down) {
                ans  = ans + (dp[i - 1] - dp[last]);
                last = i;
            }
        }
        ans = ans + (dp[index - 1] - dp[last]);
        return ans;
    }

    int findMaxElement(vector<int> &nums, int k) {
        int size = nums.size();
        if(size <= 1)
            return size;
        vector<int> dp(size + 1, 1);
        dp[0] = 0;
        
        for(int i = 2; i <= size; ++i) {
            dp[i] = max(check(nums, dp, i, k) + 1, dp[i - 1]);
        }
        return dp[size];
    }
};

int main() {
    vector<int> nums{1,1,1,1,1,1,1};
    Solution obj;
    cout<<obj.findMaxElement(nums, 0)<<endl;
	return 0;
}

