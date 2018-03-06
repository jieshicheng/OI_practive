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
    // slow way
	int trap1(vector<int>& height) {
        vector<vector<int>> graph(height.size(), vector<int>(*max_element(height.begin(), height.end()), 0));
        for( int i = 0; i != height.size(); ++i ) {
            for( int j = 0; j < height[i]; ++j ) {
                graph[i][j] = 1;
            }
        }
        // 0 空 1 石头 2 水 3 左边有石头
        for( int i = 0; i != graph.size(); ++i ) {
            if( i == 0 || i == graph.size() - 1 )
                continue;
            for( int j = 0; j != graph[i].size(); ++j ) {
                if( graph[i][j] != 0 )
                    continue;
                else if( graph[i - 1][j] == 1 && graph[i + 1][j] == 1 )
                    graph[i][j] = 2;
                else if( graph[i - 1][j] == 1 )
                    graph[i][j] = 3;
                else if( graph[i + 1][j] == 1 && graph[i - 1][j] == 3 ) {
                    graph[i][j] = 3;
                    int index = i;
                    while( graph[index][j] == 3 )
                        graph[index--][j] = 2;
                }
                else if( graph[i - 1][j] == 3 )
                    graph[i][j] = 3;
            }
        }
        int ans = 0;
        for( int i = 0; i != graph.size(); ++i ) {
            for( int j = 0; j < graph[i].size(); ++j ) {
                cout << graph[i][j] << ' ';
                if( graph[i][j] == 2 )
                    ans++;
            }
            cout << endl;
        }
        return ans;
    }
    // fast way
    int trap2(vector<int> &height) {
        if( height.size() < 3 )
            return 0;
        int left = 0, right = height.size() - 1;
        int leftHeight = height[left], rightHeight = height[right];
        int ans = 0;
        ++left;
        --right;
        while( left <= right ) {
            if( leftHeight <= rightHeight ) {
                ans += leftHeight - height[left] > 0 ? leftHeight - height[left] : 0;
                leftHeight = max(leftHeight, height[left]);
                ++left;
            }
            else {
                ans += rightHeight - height[right] > 0 ? rightHeight - height[right] : 0;
                rightHeight = max(rightHeight, height[right]);
                --right;
            }
        }
        return ans;
    }
};

int main() {
    Solution solv;
    vector<int> que{0,1,0,2,1,0,1,3,2,1,2,1};
    solv.trap(que);
    return 0;
}

