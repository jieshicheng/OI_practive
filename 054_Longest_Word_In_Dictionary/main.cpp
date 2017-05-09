#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubstr(string s, string sub)
    {
        size_t i = 0, j = 0;
        for(; i != s.size() && j != sub.size(); )
        {
            if(s[i] == sub[j])
            {
                ++i;
                ++j;
            }
            else
                ++i;
        }
        return j == sub.size();
    }


	string findLongestWord(string s, vector<string> &d)
    {
        size_t size = d.size();
        size_t index = -1;

        for(size_t i = 0; i != size; ++i)
        {
            if(isSubstr(s, d[i]))
            {
                if(index == -1 || d[i].size() > d[index].size() || (d[i].size() == d[index].size() && d[i] < d[index]))
                    index = i;
            }
        }
        if(index == -1)
            return string();
        return d[index];
    }
};

int main()
{
    vector<string> d{"ale", "apple", "monkey", "plea"};
    Solution obj;
    string s("abpcplea");
    cout<<obj.findLongestWord(s, d)<<endl;
	return 0;
}

