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
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0 )
            return 0;
        int ans = nums[0] == k ? 1 : 0;
        unordered_multiset<int> mset;
        for( int i = 1; i != size; ++i ) {
            nums[i] += nums[i - 1];
            if( nums[i] == k )
                ++ans;
        }  
        for( int i = 0; i != size; ++i ) {
            ans += mset.count(nums[i] - k);
            mset.insert(nums[i]);
        }
        return ans;
    }
};

int main() {
	Solution solv;
    vector<int> vec{1,1,1};
    cout << solv.subarraySum(vec, 2) << endl;
    return 0;
}

