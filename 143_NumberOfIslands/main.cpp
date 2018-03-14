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
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if( grid.size() == 0 )
            return ans;
        int row = grid.size();
        int col = grid[0].size();
        for( int i = 0; i != row; ++i ) {
            for( int j = 0; j != col; ++j ) {
                if( grid[i][j] == '0' )
                    continue;
                bfs(grid, i, j);
                ans++;
            }
        }
        return ans;
    }
    
    void bfs(vector<vector<char>> &grid, int row, int col) {
        queue<pair<int, int>> que;
        que.push({row, col});
        grid[row][col] = '0';
        while( !que.empty() ) {
            pair<int, int> temp = que.front();
            que.pop();
            row = temp.first;
            col = temp.second;
            if( row > 0  && grid[row - 1][col] == '1' ) {
                que.push({row - 1, col});
                grid[row - 1][col] = '0';
            }
            if( col > 0 && grid[row][col - 1] == '1' ) {
                que.push({row, col - 1});
                grid[row][col - 1] = '0';
            }
                
            if( row < grid.size() - 1 && grid[row + 1][col] == '1' ) {
                que.push({row + 1, col});
                grid[row + 1][col] = '0';
            }
                
            if( col < grid[0].size() - 1 && grid[row][col + 1] == '1' ) {
                que.push({row, col + 1});
                grid[row][col + 1] = '0';
            }
                
        }
    }	
};

int main() {
	return 0;
}

