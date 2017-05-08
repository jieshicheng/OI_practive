#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};


class Solution
{
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        return clone(node);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node)
    {
        if(node == nullptr)
            return nullptr;
        else
        {
            if(mp.find(node) == mp.end())
            {
                mp[node] = new UndirectedGraphNode(node->label);
                for(auto r : node->neighbors)
                    mp[node]->neighbors.push_back(clone(r));
            }
        }
        return mp[node];
    }
};

int main()
{
	return 0;
}

