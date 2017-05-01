#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class cmp
{
public:
    bool operator ()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    }
};


class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int>> &points)
    {
        sort(points.begin(), points.end(), [](pair<int,int> &lhs, pair<int,int> &rhs) { return lhs.second > rhs.second; });
        vector<pair<int, int>> ans;
        size_t size = points.size();
        if(size <= 1)
            return size;
        ans.push_back(points[0]);
        for(size_t i = 1; i != size; ++i)
        {
            bool flag = false;
            for(size_t j = 0; !flag && j != ans.size(); ++j)
            {
                if(points[i].first <= ans[j].second && points[i].second >= ans[j].first)
                {
                    ans[j].first = max(ans[j].first, points[i].first);
                    ans[j].second = min(ans[j].second, points[i].second);
                    flag = true;
                }
            }
            if(flag == false)
                ans.push_back(points[i]);
        }
        return ans.size();
    }
};

int main()
{
    vector<pair<int, int>> points{{3,9}, {7,12}, {3,8}, {6,8}, {9,10}, {2,9}, {0,9}, {3,9}, {0,6}, {2,8}};
    Solution obj;
    cout<<obj.findMinArrowShots(points)<<endl;


	return 0;
}

