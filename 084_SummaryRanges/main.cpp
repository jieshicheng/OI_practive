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
    vector<string> summaryRanges(vector<int>& nums) {
        string range = "0->0";
        string single = "0";
        bool flag;
        int j;
        vector<string> ans;
        for( int i = 0; i < nums.size(); ) {
            flag = false;
            j = i;
            while( nums[j] + 1 == nums[j + 1] && j + 1 < nums.size() ) {
                flag = true;
                j++;
            }            
            if( !flag ) {
                ans.push_back(to_string(nums[i]));
                ++i;
            }
            else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i = j + 1;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}

