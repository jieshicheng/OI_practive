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
	vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, {}, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> temp, const vector<int> &nums, int start) {
        if( start == nums.size() ) {
            ans.push_back(temp);
            return ;
        }
        
        dfs(ans, temp, nums, start + 1);
        temp.push_back(nums[start]);
        dfs(ans, temp, nums, start + 1);
    }
};

int main() {
	return 0;
}

