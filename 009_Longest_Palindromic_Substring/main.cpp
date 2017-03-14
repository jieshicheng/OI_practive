#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        //convert string
        int size = s.size();
        if(size < 2)
            return s;
        string new_s{"#"};
        for(int i = 0; i != size; ++i)
        {
            new_s = new_s + s[i];
            new_s = new_s + "#";
        }
        new_s[2 * size] = '#';

        //manacher
        vector<int> vec(2 * size + 1, 1);
        int max_ = 0;
        int max_index = 0;
        for(int i = 1; i != 2 * size + 1; ++i)
        {
            if(i < max_index + vec[max_index])
                vec[i] = min(vec[2 * max_index - i] , vec[max_index] + max_index - i);
            while(i - vec[i] >= 0 && i + vec[i] <= 2 * size && new_s[i - vec[i]] == new_s[i + vec[i]])
                vec[i]++;
            if(i + vec[i] > max_index + vec[max_index])
                max_index = i;
        }

        //recover
        int index = max_element(vec.begin() , vec.end()) - vec.begin();
        string ans;
        for(int i = index - vec[index] + 1; i != index + vec[index]; ++i)
        {
            if(new_s[i] != '#')
                ans = ans + new_s[i];
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "bb";
    cout<<obj.longestPalindrome(s)<<endl;
    return 0;
}
