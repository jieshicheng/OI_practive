#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void _swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void nextPermutation(vector<int>& nums) {
        if( nums.size() == 1 ) {
            return ;
        }
        if( nums.size() == 2 ) {
            _swap(nums[0], nums[1]);
            return ;
        }
        int swapIndex = -1;
        for( int i = 0; i < nums.size() - 1; ++i ) {
            if( nums[i + 1] > nums[i] ) {
                swapIndex = i;
            }
        }
        if( swapIndex == -1 ) {
            int i = 0, j = nums.size() - 1;
            while( i < j ) {
                _swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        else {
            int greater = swapIndex + 1;
            for( int i = greater; i < nums.size(); ++i ) {
                if( nums[i] > nums[swapIndex] && nums[i] <= nums[greater] ) {
                    greater = i;
                }
            }
            _swap(nums[swapIndex], nums[greater]);
            sort(nums.begin() + swapIndex + 1, nums.end());
        }
    }
};
