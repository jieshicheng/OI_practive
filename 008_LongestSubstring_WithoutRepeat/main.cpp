#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.size();
        if(size <= 1)
            return size;
        vector<int> vec(256 , -1);
        vec[s[0]] = 0;
        int max_length = 0;
        int length = 1;
        for(int i = 1; i != size; ++i)
        {
            if(vec[s[i]] == -1 || i - 1 - vec[s[i]] > length)
                length += 1;
            else
                length = i - vec[s[i]];
            vec[s[i]] = i;
            max_length = max(length , max_length);
        }
        return max_length;
    }
};


int main()
{
    return 0;
}
