#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        string index;
        map<string, int> mp;
        for(size_t i = 0; i != strs.size(); ++i)
        {
            mp[strs[i]]++;
        }
        size_t ans = 0;
        for(const auto &r : mp)
        {
            if(r.second == 1)
            {
                for(const auto &q : strs)
                {
                    if(r.first == q || r.first.size() > q.size())
                        continue;
                    size_t found = q.find(r.first);
                    if(found == string::npos)
                    {
                        ans = max(ans, r.first.size());
                    }
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};

int main()
{
    vector<string> ans{"aaaa", "aaaa", "a", "aa"};
    Solution obj;
    cout<<obj.findLUSlength(ans)<<endl;
	return 0;
}

