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
    vector<vector<int>> _matrix;

    NumMatrix(vector<vector<int>> matrix) {
        _matrix = matrix;
        for( int i = 0; i != matrix.size(); ++i ) {
            for( int j = 0 ; j != matrix[i].size(); ++j ) {
                if( i == 0 )
                    _matrix += _matrix[0][j - 1];
                else if( j == 0 )
                    _matrix += _matrix[i - 1][0];
                else
                    _matrix[i][j] += _matrix[i - 1][j] + _matrix[i][j - 1] - _matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans;
        if( row1 == 0 )
            ans = _matrix[row2][col2] - _matrix[row2][col1 - 1];
        else if( col1 == 0 )
            ans = _matrix[row2][col2] - _matrix[row1 - 1][col2];
        else
            ans = (_matrix[row2][col2] - _matrix[row1 - 1][col2] 
                - _matrix[row2][col1 - 1] + _matrix[row1 - 1][col1 - 1]);
        return ans;
    }	
};

int main() {
	return 0;
}

