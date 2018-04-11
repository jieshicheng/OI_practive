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
    bool recur(const vector<vector<int>> &matrix, int row1, int row2, int target) {
        if( row1 >= row2 ) {
            auto iter = lower_bound(matrix[row2].begin(), matrix[row2].end(), target);
            return iter != matrix[row2].end() && *iter == target;
        }
        int mid = (row1 + row2) / 2;
        return recur(matrix, row1, mid, target) || recur(matrix, mid + 1, row2, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.empty() )
            return false;
        return recur(matrix, 0, matrix.size() - 1, target);
    }
};

int main() {
	Solution solv;
    vector<vector<int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    solv.searchMatrix(matrix, 20);
    return 0;
}

