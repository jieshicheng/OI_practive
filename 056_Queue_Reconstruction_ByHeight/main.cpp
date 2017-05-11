#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct myCompare
{
    bool operator ()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        if(lhs.first == rhs.first)
            return lhs.second < rhs.second;
        else
            return lhs.first > rhs.first;
    }
};

class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        vector<pair<int, int>> ans;
        sort(people.begin(), people.end(), myCompare());
        for(const auto &r : people)
        {
            ans.insert(ans.begin() + r.second, r);
        }
        return ans;
    }
};

int main()
{
    vector<pair<int, int>> temp{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution obj;
    auto vec = obj.reconstructQueue(temp);
	for(auto r : vec)
        cout<<r.first<<" "<<r.second<<endl;
    return 0;
}

