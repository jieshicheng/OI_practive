#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution
{
public:

	vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int h = matrix.size(), w = matrix[0].size();
        queue<pair<int, int>> quence;
        for(size_t i = 0; i != matrix.size(); ++i)
        {
            for(size_t j = 0; j != matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                    quence.push({i, j});
                else
                    matrix[i][j] = 100000;
            }
        }
        vector<pair<int, int>> move = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!quence.empty())
        {
            auto temp = quence.front();
            quence.pop();
            for(int k = 0; k != 4; ++k)
            {
                int i = temp.first + move[k].first;
                int j = temp.second + move[k].second;
                if(i < 0 || i >= h || j < 0 || j >= w || matrix[i][j] <= matrix[temp.first][temp.second] + 1)
                    continue;
                quence.push({i,j});
                matrix[i][j] = matrix[temp.first][temp.second] + 1;
            }
        }
        return matrix;
    }
};

int main()
{
	return 0;
}

