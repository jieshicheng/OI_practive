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
	void moveZeroes(vector<int>& nums) {
        int i, j;
        for( i = 0, j = 0; j < nums.size(); ) {
            while( i < nums.size() && nums[i] != 0 )
                ++i;
            j = i;
            while( j < nums.size() && nums[j] == 0 ) {
                ++j;
            }
            if( i >= nums.size() || j >= nums.size() )
                break;
            myswap(nums, i, j);
        }
    }
    
    void myswap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main() {
	return 0;
}

