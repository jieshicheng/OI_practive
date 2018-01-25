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
    int rob(vector<int>& nums) {
        int takei = 0, skipi = 0, take = 0, skip = 0;
        int size = nums.size();
        for( int i = 0; i != size; ++i ) {
            skipi = max(take, skip);
            takei = skip + nums[i];
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

int main() {
	return 0;
}

