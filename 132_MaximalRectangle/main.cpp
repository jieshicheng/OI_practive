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
	int maximalRectangle(vector<vector<char>>& matrix) {
        if( matrix.size() == 0 )
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0, rowAns = 0;
        vector<int> heights(col, 0);
        for( int i = 0; i != col; ++i )
            if( matrix[0][i] == '1' )
                heights[i]++;
        rowAns = getHeightHis(heights);
        ans = max(rowAns, ans);
        
        for( int i = 1; i != row; ++i ) {
            for( int j = 0; j != col; ++j ) {
                if( matrix[i][j] == '1' )
                    if( matrix[i - 1][j] == '1' )
                        heights[j]++;
                    else
                        heights[j] = 1;
                else
                    heights[j] = 0;
            }
            rowAns = getHeightHis(heights);
            ans = max(rowAns, ans);
        }
        return ans;
    }
    
    int getHeightHis(vector<int> &heights) {
        int size = heights.size();
        if( size == 0 )
            return 0;
        stack<int> stk;
        int ans = 0;
        int i = 0;
        while( i < size ) {
            if( stk.empty() || heights[i] >= heights[stk.top()] )
                stk.push(i++);
            else {
                int index = stk.top();
                stk.pop();
                int area = heights[index] * (stk.empty() ? i : i - stk.top() - 1);
                ans = max(area, ans);
            }
        }
        while( !stk.empty() ) {
            int index = stk.top();
            stk.pop();
            int area = heights[index] * (stk.empty() ? i : i - stk.top() - 1);
            ans = max(area, ans);
        }
        return ans;
    }
};

int main() {
	return 0;
}

