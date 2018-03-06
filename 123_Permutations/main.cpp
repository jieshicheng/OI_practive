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
	vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, ans, {});
        return ans;
    }
    void dfs(vector<int> &nums, vector<bool> &used, vector<vector<int>> &ans, vector<int> temp) {
        if( temp.size() == nums.size() ) {
            ans.push_back(temp);
            return ;
        }
        for( int i = 0; i != nums.size(); ++i ) {
            if( used[i] == false ) {
                used[i] = true;
                temp.push_back(nums[i]);
                dfs(nums, used, ans, temp);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
	return 0;
}

