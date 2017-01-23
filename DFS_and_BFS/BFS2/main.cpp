/********************************

question:
    POJ 3669
    Meteor Shower
@author     jieshi
@date       1 Jan 2017

*******************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using std::pair;
using std::queue;
using std::cout;
using std::cin;
using std::vector;
using std::max_element;

class Point
{
    public:
        bool flag;
        int step;
        int time;

        Point() : flag(false),step(0),time(999) { }
};

bool set(vector<vector<Point>> &vec,int x,int y,int t)
{
    vec[x][y].time = t;
    if(x > 0)
        vec[x - 1][y].time = t;
    if(x < 300)
        vec[x + 1][y].time = t;
    if(y > 0)
        vec[x][y - 1].time = t;
    if(y < 300)
        vec[x][y + 1].time = t;
}



int main()
{
    int number;
    vector<vector<Point>> graph(301,vector<Point>(301));
    queue<pair<int,int>> que;
    vector<int> ans;

    cin>>number;
    for(int i = 0; i != number; ++i)
    {
        int x,y,t;
        cin>>x>>y>>t;
        set(graph,x,y,t);
    }
    que.push(pair<int,int>(0,0));
    graph[0][0].flag = true;
    while( !que.empty() )
    {
        pair<int,int> temp = que.front();
        que.pop();
        int localStep = graph[temp.first][temp.second].step;
        if(graph[temp.first][temp.second].time == 999)
            ans.push_back(graph[temp.first][temp.second].step);
        else
        {
            if(temp.first > 0 && !graph[temp.first - 1][temp.second].flag && localStep + 1 < graph[temp.first - 1][temp.second].time)
            {
                graph[temp.first - 1][temp.second].flag = true;
                graph[temp.first - 1][temp.second].step = localStep + 1;
                que.push(pair<int,int>(temp.first - 1,temp.second));
            }
            if(temp.first < 300 && !graph[temp.first + 1][temp.second].flag && localStep + 1 < graph[temp.first + 1][temp.second].time)
            {
                graph[temp.first + 1][temp.second].flag = true;
                graph[temp.first + 1][temp.second].step = localStep + 1;
                que.push(pair<int,int>(temp.first + 1,temp.second));
            }
            if(temp.second > 0 && !graph[temp.first][temp.second - 1].flag && localStep + 1 < graph[temp.first][temp.second - 1].time)
            {
                graph[temp.first][temp.second - 1].flag = true;
                graph[temp.first][temp.second - 1].step = localStep + 1;
                que.push(pair<int,int>(temp.first,temp.second - 1));
            }
            if(temp.second < 300 && !graph[temp.first][temp.second + 1].flag && localStep + 1 < graph[temp.first][temp.second + 1].time)
            {
                graph[temp.first][temp.second + 1].flag = true;
                graph[temp.first][temp.second + 1].step = localStep + 1;
                que.push(pair<int,int>(temp.first,temp.second + 1));
            }
        }
    }
    if( ans.empty() )
        cout<<-1;
    else
        cout<<*max_element(ans.begin(),ans.end());

    return 0;
}



