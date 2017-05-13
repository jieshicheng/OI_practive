#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        map<char, set<int>> mp;
        for(int i = 0; i != t.size(); ++i)
        {
            mp[t[i]].insert(i);
        }
        int bord = -1;
        for(int i = 0; i != s.size(); ++i)
        {
            auto it = mp.find(s[i]);
            if(it != mp.end())
            {
                bool flag = false;
                for(const auto &index : it->second)
                {
                    if(index > bord)
                    {
                        flag = true;
                        bord = index;
                        it->second.erase(index);
                        break;
                    }
                }
                if(flag == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string t("aqweqweqweqwaaabbbbbb");
    string s("abc");
    Solution obj;
    cout<<obj.isSubsequence(s, t)<<endl;
	return 0;
}

