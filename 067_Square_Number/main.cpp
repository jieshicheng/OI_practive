#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool check(string str)
    {
        vector<bool> used(10, true);
        for(auto ch : str)
        {
            if(used[ch - '0'] == false)
                return false;
            else
            {
                used[ch - '0'] = false;
            }
        }
        return true;
    }

    vector<string> numberInit()
    {
        vector<string> number;
        long long unsigned temp;
        for(long long unsigned i = 0; i < 100000; ++i)
        {
            temp = i * i;
            ostringstream out;
            out<<temp;
            if( check(out.str()) )
            {
                number.push_back(out.str());
            }
        }
        return number;
    }

    void dfs(int index, int length, string str, int &ans, const vector<string> &strs)
    {
        if(length > 10 || !check(str))
            return ;
        if(length == 10 && check(str))
        {
            ++ans;
            return ;
        }
        for(int i = index; i != strs.size(); ++i)
        {
            dfs(i + 1, length + strs[i].size(), str + strs[i], ans, strs);
        }
    }

    int calculate()
    {
        vector<string> strs = numberInit();
        int ans = 0;
        string s = "";
        dfs(0, 0, s, ans, strs);
        return ans;
    }
};

int main()
{
    Solution obj;
    cout<<obj.calculate()<<endl;
	return 0;
}

