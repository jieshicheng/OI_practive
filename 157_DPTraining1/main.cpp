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
    int recur(const vector<vector<bool>> &graph, vector<int> &dp, int i) {
        if( dp[i] != -1 ) 
            return dp[i];
        dp[i] = 1;
        for( int j = 0; j != graph.size(); ++j ) {
            if( graph[i][j] ) {
                dp[i] = max(recur(graph, dp, j) + 1, dp[i]);
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
        int maxIndex = 0;
        for( int i = 1; i != size; ++i ) {
            if( recur(graph, dp, i) > dp[maxIndex] )
                maxIndex = i;
        }
        print_ans(dp, ans, maxIndex, graph);
        return ans;
    }

    void print_ans(const vector<int> &dp, vector<int> &ans, int i, const vector<vector<bool>> &graph) {
        ans.push_back(i);
        for( int j = 0; j != graph.size(); ++j ) {
            if( graph[i][j] && dp[i] == dp[j] + 1 ) {
                print_ans(dp, ans, j, graph);
                break;
            }
        }
    }

    vector<vector<bool>> getGraph(const vector<pair<int, int>> &matrix) {
        vector<vector<bool>> graph(matrix.size(), vector<bool>(matrix.size(), false));
        for( int i = 0; i != graph.size(); ++i ) {
            for( int j = 0; j != graph.size(); ++j ) {
                if( matrix[i].first < matrix[j].first && matrix[i].second < matrix[j].second ) {
                    graph[i][j] = true;
                    continue;
                }
                else if( matrix[i].first < matrix[j].second && matrix[i].second < matrix[j].first ) {
                    graph[i][j] = true;
                }
            }
        }
        /*
        for( auto i : graph ) {
            for( auto j : i )
                cout << j << " ";
            cout << endl;
        }*/
        return graph;
    }
};

int main() {
	Solution solv;
    vector<int> ans = solv.answer({{1,2}, {3,4}, {5,6}, {6,2}, {6,7}});
    for( auto i : ans )
        cout << i << endl;
    return 0;
}

