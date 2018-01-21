#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        vector<int> ans(nums.size(), 0);
        ans[0] = 1;
        for( int i = 1; i != nums.size(); ++i ) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }
        int right = 1;
        for( int i = nums.size() - 1; i >= 0; --i ) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }
        return ans;
    }	
};

int main() {
	return 0;
}

