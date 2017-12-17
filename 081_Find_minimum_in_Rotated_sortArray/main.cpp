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
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for( int i = 1; i != nums.size(); ++i ) {
            if( nums[i] > nums[i - 1] )
                continue;
            else {
                ans = nums[i];
                return ans;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}

