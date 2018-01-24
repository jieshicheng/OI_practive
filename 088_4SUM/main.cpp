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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        vector<vector<int>> ans;
        if( nums[0] * 4 > target || nums[size - 1] * 4 < target )
            return ans;
        for( int i = 0; i != size; ++i ) {
            int aim = nums[i];
            if( i > 0 && nums[i - 1] == aim )
                continue;
            if( aim + nums[size - 1] * 3 < target)
                continue;
            if( aim * 4 > target )
                break;
            if( aim * 4 == target ) {
                if( i + 3 < size && nums[i + 3] == aim ) {
                    ans.push_back({aim, aim, aim, aim});
                    continue;
                }
            }
            threeSum(nums, i + 1, size, ans, aim, target - aim);
        }
        return ans;
    }

    void threeSum(vector<int> &nums, int begin, int end, vector<vector<int>> &ans, int num1, int target) {
        if( begin + 1 >= end - 1 )
            return ;
        if( nums[begin] * 3 > target || nums[end - 1] * 3 < target )
            return ;

        for( int i = begin; i != end; ++i ) {
            int aim = nums[i];
            if( i > 0 && nums[i - 1] == aim )
                continue;
            if( aim + nums[end - 1] * 2 < target )
                continue;
            if( aim * 3 > target )
                break;
            if( aim * 3 == target ) {
                if( i + 2 < end && nums[i + 2] == aim ) {
                    ans.push_back({num1, aim, aim, aim});
                    continue;
                }
            }
            twoSum(nums, i + 1, end, ans, num1, aim, target - aim);
        }
    }

    void twoSum(vector<int> &nums, int begin, int end, vector<vector<int>> &ans, int num1, int num2, int target) {
        if( begin >= end - 1 )
            return ;
        if( nums[begin] * 2 > target || nums[end - 1] * 2 < target )
            return ;
        
        int i = begin, j = end - 1;
        while( i < j ) {
            int sum = nums[i] + nums[j];
            if( sum == target ) {
                ans.push_back({num1, num2, nums[i], nums[j]});
                while( i++ < j && nums[i] == nums[i - 1] );
                while( j-- > i && nums[j] == nums[j + 1] );
            }
            if( sum < target )
                ++i;
            if( sum > target )
                --j;
        }
    }
};

int main() {
    Solution solv;
    vector<int> test{1, 0, -1, 0, 2, -2};
    for( const auto &item : solv.fourSum(test, 0) ) {
        for( const auto &r : item )
            cout <<  r << ' ';
        cout << endl;
    }
	return 0;
}

