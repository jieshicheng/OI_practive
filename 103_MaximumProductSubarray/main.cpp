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
	int maxProduct(vector<int>& nums) {
        if( nums.size() == 1 )
            return nums[0];
        int prePlus = 1, preMinus = 1;
        int plus, minus;
        int ans = 0;
        for( int i = 0; i != nums.size(); ++i ) {
            if( nums[i] >= 0 ) {
                plus = max(prePlus * nums[i], nums[i]);
                minus = min(preMinus * nums[i], nums[i]);
            }
            else {
                plus = max(preMinus * nums[i], nums[i]);
                minus = min(prePlus * nums[i], nums[i]);
            }
            prePlus = plus;
            preMinus = minus;
            ans = max(plus, ans);
        }
        return ans;   
    }
};

int main() {
	return 0;
}

