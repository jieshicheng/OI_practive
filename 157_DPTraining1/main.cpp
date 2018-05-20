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
    int recur(const vector<vector<bool>> &graph, vector<int> &dp, i) {
        if( dp[i] != -1 ) 
            return dp[i];
        dp[i] = 1;
        for( int j = 0; j != graph.size(); ++j ) {
            if( graph[i][j] ) {
                dp[i] = max(recur(j) + 1, dp[i]);
            }
        }
        return dp[i];
    }

    vector<int> answer(const vector<pair<int, int>> &matrix) {
        int size = matrix.size();
        vector<int> ans;
        if( size == 0 ) {
            return ans;
        }
        vector<vector<bool>> graph = getGraph(matrix);
        vector<int> dp(size, -1);
        recur(graph, dp, 0);
        int maxIndex = 0
        for( int i = 1; i != size; ++i ) {
            if( recur(graph, dp, i) > dp[maxIndex] )
                maxIndex = i;
        }
        print_ans(dp, ans, maxIndex, graph);
        return ans;
    }

    void print_ans(const vector<int> &dp, vector<int> &ans, int i, const vector<vector<bool>> &graph) {
        ans.push_back(i);
        for( int j = 0; j != size; ++j ) {
            if( graph[i][j] && dp[i] == dp[j] + 1 ) 
                print_ans;
                break;
        }
    }

    vector<vector<bool>> getGraph(const vector<pair<int, int>> &matrix) {
        vector<vector<bool>> graph(size, vector<bool>(size, false));
        for( int i = 0; i != size; ++i ) {
            for( int j = 0; j != size; ++j ) {
                if( matrix[i].first < matrix[j].first && matrix[i].second < matrix[j].second ) {
                    graph[i][j] = true;
                    continue;
                }
                else if( matrix[i].first < matrix[j].second && matrix[i].second < matrix[j].first ) {
                    graph[i][j] = true;
                }
            }
        }
        return graph;
    }
};

int main() {
	return 0;
}

