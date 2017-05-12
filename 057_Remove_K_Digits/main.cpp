#include <iostream>
#include <string>


using namespace std;

class Solution
{
public:
	string removeKdigits(string num, int k)
    {
        size_t size = num.size();
        if(size <= k)
            return string("0");
        string str(size, ' ');
        str[0] = num[0];
        size_t i, j;
        for(i = 1, j = 0; i < size; ++i)
        {
            char ch = num[i];
            while(k > 0 && ch < str[j])
            {
                --j;
                --k;
            }
            str[++j] = ch;
        }
        cout<<j<<" "<<k<<endl;
        if(k != 0)
            str = str.substr(0, j + 1 - k);
        else
            str = str.substr(0, j + 1);
        while(str.size() != 1 && str[0] == '0')
            str = str.substr(1, str.size());
        return str;
    }
};

int main()
{
    string s("1432219");
    Solution obj;
    cout<<obj.removeKdigits(s, 3)<<endl;
	return 0;
}

