#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    double searchPath(string a, string b, unordered_map<string, unordered_map<string, double>> &mp, unordered_set<string> &st)
    {
        if(mp[a].find(b) != mp[a].end())
            return mp[a][b];
        else
        {
            for(const auto &r : mp[a])
            {
                if(st.find(r.first) == st.end())
                {
                    st.insert(r.first);
                    double temp = searchPath(r.first, b, mp, st);
                    st.erase(r.first);
                    if(temp)
                        return temp * r.second;
                }
            }
        }
        return 0;
    }


    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &value, 
                                vector<pair<string, string>> queries)
    {
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> mp;
        unordered_set<string> st;


        size_t size = value.size();
        for(size_t i = 0; i != size; ++i)
        {
            mp[equations[i].first].insert(make_pair(equations[i].second, value[i]));
            mp[equations[i].second].insert(make_pair(equations[i].first, 1 / value[i]));
        }
        size = queries.size();
        for(size_t i = 0; i != size; ++i)
        {
            string a = queries[i].first, b = queries[i].second;
            double temp = searchPath(a, b, mp, st);
            if(temp)
                ans.push_back(temp);
            else
                ans.push_back(-1.0);
        }
        return ans;
    }
};

int main()
{
    vector<pair<string, string>> equations{{"a", "b"}, {"b", "c"}};
    vector<double> values{2.0, 3.0};
    vector<pair<string, string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    Solution obj;
    vector<double> ans = obj.calcEquation(equations, values, queries);
	for(auto r : ans)
        cout<<r<<" ";
    cout<<endl;
    return 0;
}

