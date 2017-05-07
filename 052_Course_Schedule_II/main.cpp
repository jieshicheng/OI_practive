#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        int size = prerequisites.size();
        if(!size)
            return vector<int>();
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
        vector<int> path;
        for(auto it = graph.begin(); it != graph.end(); ++it)
        {
            int times = 0;
            if(degree.count(it->first) == 0)
            {
                ans.insert(it->first);
                dfs(graph, it->first, flag, times, numCourses, ans, path);
            }
        }
        if(flag == false || ans.size() < graph.size())
            return vector<int>();
        else
        {
            ans.clear();
            for(auto it = path.begin(); it != path.end(); )
            {
                if(ans.count(*it) == 0)
                    ans.insert(*it++);
                else
                {
                    it = path.erase(it);
                }
            }
            for(int i = 0; i != numCourses; ++i)
            {
                if(ans.count(i) == 0)
                    path.push_back(i);
            }
            return vector<int>(path.rbegin(), path.rend());
        }
    }

    void dfs(unordered_map<int, unordered_set<int>> &graph, int pos, bool &flag, int &times, int numCourses, unordered_set<int> &ans, vector<int> &path)
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
            dfs(graph, r, flag, times, numCourses, ans, path);
        }
        path.push_back(pos);
        return ;
    }
};

int main()
{
    vector<pair<int, int>> graph{{5,8}, {3,5}, {1,9}, {4,5}, {0,2}, {7,8}, {4,9}};
    Solution obj;
    auto temp = obj.findOrder(10, graph);
    for(auto r : temp)
        cout<<r<<" ";
    cout<<endl;
	return 0;
}
