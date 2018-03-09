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
	int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if( size == 0 )
            return 0;
        stack<int> stk;
        int i = 0;
        int area, index, ans = 0;
        while( i < size ) {
            if( stk.empty() || heights[i] >= heights[stk.top()] )
                stk.push(i++);
            else {
                index = stk.top();
                stk.pop();
                area = heights[index] * (stk.empty() ? i : i - stk.top() - 1);
                ans = max(area, ans);
            }
        }
        while( !stk.empty() ) {
            index = stk.top();
            stk.pop();
            area = heights[index] * (stk.empty() ? i : i - stk.top() - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};

int main() {
	return 0;
}

