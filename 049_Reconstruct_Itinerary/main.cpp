#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        vector<string> ans;
        map<string, multiset<string>> graph;
        size_t size = tickets.size();
        for(size_t i = 0; i != size; ++i)
        {
            graph[tickets[i].first].insert(tickets[i].second);
        }
        dfs("JFK", ans, graph);
        return vector<string>(ans.rbegin(), ans.rend());
    }

    void dfs(const string &s, vector<string> &ans, map<string, multiset<string>> &graph)
    {
        while(graph[s].size())
        {
            string next = graph[s].begin();
            graph[i].erase(graph[i].begin());
            dfs(next, ans, graph);
        }
        ans.push_back(next);
    }
};

int main()
{
	return 0;
}
