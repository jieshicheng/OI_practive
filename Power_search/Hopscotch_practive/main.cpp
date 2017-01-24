/*********************************

question:
    POJ 3050
    Hopscotch
@authro     jieshi
@date       5 Jan 2017


************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::set;
using std::cout;
using std::cin;
using std::vector;

void DFS(const vector<vector<int>> &graph,int deep,int value,set<int> &ans,int x,int y)
{
    const static int dx[] = {-1,0,1,0};
    const static int dy[] = {0,-1,0,1};

    if(deep == 5)
    {
        ans.insert(value);
        return ;
    }
    else
    {
        for(int i = 0; i != 4; ++i)
        {
            if( (x + dx[i] >= 0 && x + dx[i] <5) && (y + dy[i] >= 0 && y + dy[i] < 5) )
                DFS(graph,deep + 1,value * 10 + graph[x + dx[i]][y + dy[i]],ans,x + dx[i],y + dy[i]);
        }
    }
}

int main()
{
    set<int> ans;
    vector<vector<int>> graph(5,vector<int>(5));
    for(int i = 0; i != 5; ++i)
    {
        for(int j = 0; j != 5; ++j)
        {
            int temp;
            cin>>temp;
            graph[i][j] = temp;
        }
    }

    for(int i = 0; i != 5; ++i)
    {
        for(int j = 0; j != 5; ++j)
        {
            DFS(graph,0,graph[i][j],ans,i,j);
        }
    }

    cout<<ans.size();
    return 0;
}
