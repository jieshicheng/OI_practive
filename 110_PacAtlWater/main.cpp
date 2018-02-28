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
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if( matrix.empty() )
            return vector<pair<int, int>>();
        vector<vector<bool>> succ(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<pair<int, int>> ans;
        for( int i = 0; i != matrix.size(); ++i ) {
            for( int j = 0; j != matrix[0].size(); ++j ) {
                bool pac = false, atl = false;
                dfs(succ, matrix, i, j, pac, atl);
                if( pac && atl ) {
                    ans.push_back({i, j});
                    succ[i][j] = true;
                }
            }
        }
        return ans;
    }
    
    void dfs(const vector<vector<bool>> &succ, vector<vector<int>> &matrix, int row, int col, bool &pac, bool &atl) {
        if( succ[row][col] ) {
            pac = atl = true;    
        }
        if( pac && atl )
            return ;
        if( row < 0 || col < 0 ) {
            pac = true;
            return ;
        }
        if( row > matrix.size() - 1 || col > matrix[0].size() - 1) {
            atl = true;
            return ;
        }
        if( row - 1 < 0 ) {
            pac = true;
        }
        else if( matrix[row][col] >= matrix[row - 1][col] ) {
            matrix[row][col] += 1;
            dfs(succ, matrix, row - 1, col, pac, atl);
            matrix[row][col] -= 1;
        }
        if( col - 1 < 0 ) {
            pac = true;
        }
        else if(matrix[row][col] >= matrix[row][col - 1] ) {
            matrix[row][col] += 1;
            dfs(succ, matrix, row, col - 1, pac, atl);
            matrix[row][col] -= 1;
        }
        if( row + 1 >= matrix.size() ) {
            atl = true;
        }
        else if(matrix[row][col] >= matrix[row + 1][col] ) {
            matrix[row][col] += 1;
            dfs(succ, matrix, row + 1, col, pac, atl);
            matrix[row][col] -= 1;
        }
        if( col + 1 >= matrix[0].size() ) {
            atl = true;
        }
        else if(matrix[row][col] >= matrix[row][col + 1] ) {
            matrix[row][col] += 1;
            dfs(succ, matrix, row, col + 1, pac, atl);
            matrix[row][col] -= 1;
        }
    }
};

int main() {
    Solution solv;
    vector<vector<int>> matrix{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    auto ans = solv.pacificAtlantic(matrix);
    for( auto iter : ans ) {
        cout << iter.first << " " << iter.second << endl;
    }
    return 0;

}

