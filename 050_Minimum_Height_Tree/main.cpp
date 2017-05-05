#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        map<int, multiset<int>> graph;
        for(int i = 0; i != n; ++i)
        {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }
        vector<int> leave;
        for(int i = 0; i != n; ++i)
        {
            if(graph[i].size() == 1)
                leave.push_back(i);
        }
        while(n > 2)
        {
            vector<int> newLeave;
            n = n - leave.size();
            for(int i : leave)
            {
                int j = *graph[i].begin();
                graph.erase(i);
                graph[j].erase(i);
                if(graph[j].size() == 1)
                    newLeave.push_back(j);
            }
            leave = newLeave;
        }
        return leave;
    }
};

int main()
{

	return 0;
}

