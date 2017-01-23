/**********************************

question:
    POJ 3009
    Curling

@author jieshi
@date 31 Dev 2016

**********************************/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::max;
using std::min;
using std::min_element;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

bool yCheck(const vector<vector<char>> &graph,const int width,int lhs,int rhs);
bool xCheck(const vector<vector<char>> &graph,const int height,int lhs,int rhs);
void solv(vector<vector<char>> graph,const pair<int,int> &localPoint,
            vector<int> &ans,int count,const pair<int,int> &point);

int main()
{
    int height;
    int width;
    cin>>height>>width;
    vector<vector<char>> graph(height);
    pair<int,int> beginPoint;
    pair<int,int> endPoint;

    for(int i = 0; i != height; ++i)
    {
        for(int j = 0; j != width; ++j)
        {
            char ch;
            cin>>ch;
            if(ch == '2')
                beginPoint = {i,j};
            if(ch == '3')
                endPoint = {i,j};
            graph[i].push_back(ch);
        }
    }
    int count = 0;
    vector<int> ans;

    solv(graph,beginPoint,ans,count,beginPoint);
    if(ans.empty())
        cout<<-1;
    else
        cout<<*(min_element(ans.cbegin(),ans.cend()));
    return 0;
}

/**
 *action:   DFS
 *graph:    map
 *localPoint:   the postion about where is begin
 *ans:      step number set.
 *point:    move to the wall.wall's postion
 */
void solv( vector<vector<char>> graph,const pair<int,int> &localPoint,
            vector<int> &ans,int count,const pair<int,int> &point )
{
    ++count;
    graph[point.first][point.second] = '0';
    graph[localPoint.first][localPoint.second] = '0';

    // x search
    for(int i = 0; i != graph[0].size(); ++i)
    {
        if(graph[localPoint.first][i] == '3' && xCheck(graph,localPoint.first,localPoint.second,i))
        {
            ans.push_back(count);
            return ;
        }
        if(graph[localPoint.first][i] == '1' && xCheck(graph,localPoint.first,localPoint.second,i))
        {
            pair<int,int> changePoint = {localPoint.first,i};
            if(localPoint.second < i)
            {
                solv(graph,pair<int,int>(localPoint.first,i - 1),ans,count,changePoint);
            }
            else
            {
                solv(graph,pair<int,int>(localPoint.first,i + 1),ans,count,changePoint);
            }
        }
    }

    // y search
    for(int i = 0; i != graph.size(); ++i)
    {
        if(graph[i][localPoint.second] == '3' && yCheck(graph,localPoint.second,localPoint.first,i))
        {
                ans.push_back(count);
                return ;
        }
        
        if(graph[i][localPoint.second] == '1' && yCheck(graph,localPoint.second,localPoint.first,i))
        {
            pair<int,int> changePoint2 = {i,localPoint.second};
            if(localPoint.first < i)
            {
                solv(graph,pair<int,int>(i - 1,localPoint.second),ans,count,changePoint2);                }
            else
            {
                solv(graph,pair<int,int>(i + 1,localPoint.second),ans,count,changePoint2);
            }
        }
    }
}

/**
 *action:   judge whether can move to the wall
 *graph:    map
 *height:   localPoint's height
 *lhs:      local's width postion
 *rhs:      the wall's width postion
 */
bool xCheck(const vector<vector<char>> &graph,const int height,int lhs,int rhs)
{
    int smaller = min(lhs,rhs);
    int bigger = max(lhs,rhs);
    if(smaller + 1 == bigger)
        return false;
    for(int temp = smaller + 1; temp != bigger; ++temp)
    {
        if(graph[height][temp] == '1')
            return false;
    }
    return true;
}

/**
 *action:   same means like up function.
 */
bool yCheck(const vector<vector<char>> &graph,const int width,int lhs,int rhs)
{
    int smaller = min(lhs,rhs);
    int bigger = max(lhs,rhs);
    if(smaller + 1 == bigger)
        return false;
    for(int temp = smaller + 1; temp != bigger; ++temp)
    {
        if(graph[temp][width] == '1')
            return false;
    }
    return true;
}







