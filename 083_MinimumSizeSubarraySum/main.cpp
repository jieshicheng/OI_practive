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
    int minSubarrayLen(int s, vector<int> &nums) {
        long long sum = 0;
        int length = 0, ans = 9999;

        for( int i = 0; i != nums.size(); ++i ) {
            sum += nums[i];
            length++;
            while( sum >= s ) {
                ans = min(ans, length);
                sum -= nums[i - length + 1];
                length--;
            }
        }
        return ans == 9999 ? 0 : ans;
    }
};

int main() {
	return 0;
}

