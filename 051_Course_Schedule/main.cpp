#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        int size = prerequisites.size();
        if(!size)
            return true;
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> degree;
        for(int i = 0; i != size; ++i)
        {
            graph[prerequisites[i].first];
            graph[prerequisites[i].second];
            degree.insert(prerequisites[i].first);
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }
        unordered_set<int> ans;
        bool flag = true;
        for(auto it = graph.begin(); it != graph.end(); ++it)
        {
            int times = 0;
            if(degree.count(it->first) == 0)
            {
                ans.insert(it->first);
                dfs(graph, it->first, flag, times, numCourses, ans);
            }
        }
        if(flag == false || ans.size() < graph.size())
            return false;
        else
            return true;
    }

    void dfs(unordered_map<int, unordered_set<int>> &graph, int pos, bool &flag, int &times, int numCourses, unordered_set<int> &ans)
    {
        ++times;
        if(times > 2 * numCourses)
        {
            flag = false;
            return ;
        }
        if(!flag)
            return ;
        for(auto r : graph[pos])
        {
            ans.insert(r);
            dfs(graph, r, flag, times, numCourses, ans);
        }
        return ;
    }
};

int main()
{
    vector<pair<int, int>> graph{{5,8}, {3,5}, {1,9}, {4,5}, {0,2}, {7,8}, {4,9}};
    Solution obj;
    cout<<obj.canFinish(10, graph)<<endl;
	return 0;
}

