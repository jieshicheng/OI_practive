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
    int up[3] = {-1, 0, 1};
    int left[3] = {-1, 0, 1};

    void searchGraph(vector<vector<char>> &graph, int row, int col) {
        graph[row][col] = '*';

        for(int i = 0; i != 3; ++i) {
            for(int j = 0; j != 3; ++j) {
                int __i = row + up[i];
                int __j = col + left[j];
                if(__i < 0 || __i > graph.size() - 1 || __j < 0 || __j > graph[0].size() - 1)
                    continue;
                if(graph[__i][__j] == '@') {
                    searchGraph(graph, __i, __j);
                }
            }
        }
    }

    int findAns(vector<vector<char>> &graph) {
        int ans = 0;
        for(int i = 0; i != graph.size(); ++i) {
            for(int j = 0; j != graph[0].size(); ++j) {
                if(graph[i][j] == '@') {
                    searchGraph(graph, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> graph = {{'*', '*', '*', '@'},
                                  {'*', '@', '*', '@'},
                                  {'*', '@', '*', '@'},
                                  {'@', '*', '*', '@'},
                                  {'*', '*', '*', '@'},
                                 };

    Solution obj;
    cout << obj.findAns(graph) << endl;

	return 0;
}

