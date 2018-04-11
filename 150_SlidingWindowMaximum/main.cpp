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
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int size = nums.size();
        for( int i = 0; i != size; ++i ) {
            while( !dq.empty() && nums[dq.back()] < nums[i] )
                dq.pop_back();
            dq.push_back(i);
            while( dq.front() <= i - k )
                dq.pop_front();
            if( i - k >= -1 )
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main() {
	return 0;
}

