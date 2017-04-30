#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSub(const string &s, const vector<string> &strs)
    {
        for(size_t i = 0; i != strs.size(); ++i)
        {
            if(s == strs[i])
                continue;
            size_t j = 0, k = 0;
            while(j < s.size() && k < strs[i].size())
            {
                if(s[j] == strs[i][k])
                {
                    ++j;
                    ++k;
                }
                else
                    ++k;
            }
            if(j >= s.size())
                return true;
        }
        return false;
    }


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
                if( !isSub(r.first, strs) )
                {
                    ans = max(ans, r.first.size());
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};

int main()
{
    vector<string> ans{"aabbcc", "aabbcc", "abc", "dc"};
    Solution obj;
    cout<<obj.findLUSlength(ans)<<endl;
	return 0;
}

