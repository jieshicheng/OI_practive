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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, 0, target, {});
        return ans;
    }
    
    void dfs(vector<vector<int>> &ans, const vector<int> &nums, int start, int target, vector<int> temp) {
        if( target == 0 ) {
            ans.push_back(temp);
            return ;
        }
        if( start >= nums.size() )
            return ;
        else if( target < 0 )
            return ;
        int step = target / nums[start];
        int begin = 1;
        dfs(ans, nums, start + 1, target, temp);
        while( begin <= step ) {
            temp.push_back(nums[start]);
            dfs(ans, nums, start + 1, target - nums[start] * begin, temp);
            ++begin;
        }
    }
};

int main() {
	return 0;
}

