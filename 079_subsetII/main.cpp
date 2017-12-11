#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        long long binarySet = 1;
        int size = nums.size();
        while( size ) {
            binarySet *= 2;
            size--;
        }
        binarySet--;
        vector<vector<int>> ans;
        for( int i = 0; i <= binarySet; ++i ) {
            int i_copy = i;
            vector<int> temp;
            for( int step = 0; step < nums.size(); ++step ) {
                int left = i_copy % 2;
                i_copy /= 2;
                if( left == 1 ) {
                    temp.push_back(nums[step]);
                }
            }
            sort(temp.begin(), temp.end());
            if( !judge(ans, temp) ) {
                ans.push_back(temp);
            }
        }
        return ans;
    }

    bool judge(vector<vector<int>> check, vector<int> aim) {
        for( int i = 0; i != check.size(); ++i ) {
            if( check[i].size() != aim.size() )
                continue;
            if( aim == check[i] )
                return true;
        }
        return false;
    }
};

