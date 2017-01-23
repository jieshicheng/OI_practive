/*******************************

question:
    POJ 1979 Red and Black

@author jieshicheng
@date   30 Dev 2016


*******************************/

#include <iostream>
#include <vector>
#include <utility>

using std::pair;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

void solv(vector<vector<char>> &graph,const pair<int,int> &pos,int &count);

int main()
{
    int width;
    int height;
    pair<int,int> beginPoint;

    cin>>width>>height;
    vector<vector<char>> graph(height,vector<char>(width));
    for(int i = 0; i != height; ++i)
    {
        for(int j = 0; j != width; ++j)
        {
            char ch;
            cin>>ch;
            if(ch == '@')
                beginPoint = {i,j};
            graph[i][j] = ch;
        }
    }
    int count = 0;
    solv(graph,beginPoint,count);
    cout<<count;
    return 0;
}

/**
 *  action: DFS
 *  graph   map
 *  pos     local postion
 *  count   step number
 */
void solv(vector<vector<char>> &graph,const pair<int,int> &pos,int &count)
{
    ++count;
    graph[pos.first][pos.second] = '#';

    if(pos.first - 1 >= 0 && graph[pos.first - 1][pos.second] == '.')
    {
        solv(graph,pair<int,int>(pos.first - 1,pos.second),count);
    }
    if(pos.first + 1 < graph.size() && graph[pos.first + 1][pos.second] == '.')
    {
        solv(graph,pair<int,int>(pos.first + 1,pos.second),count);
    }
    if(pos.second - 1 >= 0 && graph[pos.first][pos.second - 1] == '.')
    {
        solv(graph,pair<int,int>(pos.first,pos.second - 1),count);
    }
    if(pos.second + 1 <= graph[1].size() && graph[pos.first][pos.second + 1] == '.')
    {
        solv(graph,pair<int,int>(pos.first,pos.second + 1),count);
    }
}
