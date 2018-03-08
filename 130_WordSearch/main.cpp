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
	bool exist(vector<vector<char>>& board, string word) {
        if( word.empty() )
            return true;
        if( board.size() == 0 )
            return false;
        vector<vector<bool>> graph(board.size(), vector<bool>(board[0].size(), false));
        for( int i = 0; i != board.size(); ++i ) {
            for( int j = 0; j != board[i].size(); ++j )
                if( board[i][j] == word[0] ) {
                    graph[i][j] = true;
                    if( dfs(board, word, 1, i, j, graph) )
                        return true;
                    graph[i][j] = false;
                }
        }
        return false;
    }
    
    bool dfs(const vector<vector<char>> &board, const string &word, int index, int row, int col, vector<vector<bool>> &graph) {
        if( index == word.size() )
            return true;
        if( row > 0 && !graph[row - 1][col] && board[row - 1][col] == word[index] ) {
            graph[row - 1][col] = true;
            if( dfs(board, word, index + 1, row - 1, col, graph) )
                return true;
            graph[row - 1][col] = false;
        }
        if( row + 1 < board.size() && !graph[row + 1][col] && board[row + 1][col] == word[index] ) {
            graph[row + 1][col] = true;   
            if( dfs(board, word, index + 1, row + 1, col, graph) )
                return true;
            graph[row + 1][col] = false;
        }
        if( col > 0 && !graph[row][col - 1] && board[row][col - 1] == word[index] ) {
            graph[row][col - 1] = true;
            if( dfs(board, word, index + 1, row, col - 1, graph) )
                return true;
            graph[row][col - 1] = false;
        }
        if( col + 1 < board[row].size() && !graph[row][col + 1] && board[row][col + 1] == word[index] ) {
            graph[row][col + 1] = true;
            if( dfs(board, word, index + 1, row, col + 1, graph) )
                return true;
            graph[row][col + 1] = false;
        }
        return false;
    }
};

int main() {
	return 0;
}

