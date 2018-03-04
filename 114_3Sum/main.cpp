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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if( size == 0 )
            return ans;
        if( nums[0] * 3 > 0 || nums[size - 1] * 3 < 0 )
            return ans;
        for( int i = 0; i != size; ++i ) {
            if( i > 0 && nums[i] == nums[i - 1] )
                continue;
            else if( nums[i] + nums[size - 1] * 2 < 0 )
                continue;
            else if( nums[i] * 3 > 0 )
                break;
            else if( nums[i] * 3 == 0  && i + 2 < size && nums[i] == nums[i + 2] ) {
                ans.push_back({nums[i], nums[i], nums[i]});
                continue;
            }
            else
                twoSum(nums, i + 1, size - 1, ans, 0 - nums[i], nums[i]);
        }
        return ans;
    }
    
    void twoSum(vector<int> &nums, int begin, int end, vector<vector<int>> &ans, int aim, int lastNum) {
        if( begin + 1 > end )
            return ;
        if( nums[begin] * 2 > aim || nums[end] * 2 < aim )
            return ;
        while( begin < end ) {
            int sum = nums[begin] + nums[end];
            if( sum == aim ) {
                ans.push_back({lastNum, nums[begin], nums[end]});
                while( begin++ < end && nums[begin] == nums[begin - 1]);
                while( end-- > begin && nums[end] == nums[end + 1]);
            }
            else if( sum > aim )
                end--;
            else 
                begin++;
        }
    }
    	
};

int main() {
	return 0;
}

