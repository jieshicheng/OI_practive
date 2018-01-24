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
    int findDuplicate3(vector<int>& nums)
    {
	    if (nums.size() > 1)
	    {
		    int slow = nums[0];
		    int fast = nums[nums[0]];
		    while (slow != fast)
		    {
			    slow = nums[slow];
			    fast = nums[nums[fast]];
		    }   
		    fast = 0;
		    while (fast != slow)
		    {
			    fast = nums[fast];
			    slow = nums[slow];
		    }
		    return slow;
	    }
	    return -1;
    }	
};

int main() {
    Solution solv;
    vector<int> vec{1,6,3,4,5,6,2};
    cout << solv.findDuplicate3(vec);
	return 0;
}

