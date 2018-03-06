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
	void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for( int i = 0; i != matrix.size(); ++i ) {
            for( int j = 0; j <= i; ++j ) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};

int main() {
	return 0;
}

