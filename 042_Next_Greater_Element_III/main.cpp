#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    void swap(char &lhs, char &rhs)
    {
        char temp = lhs;
        lhs = rhs;
        rhs = temp;
    }

    int nextGreaterElement(int n)
    {
        char p[32];
        sprintf(p, "%d", n);
        string s(p);
        int size = s.size();
        int i;
        for(i = size - 1; i >= 0; --i)
        {
           bool flag = false;
           int index = i;
           for(int j = i + 1; j < size; ++j)
           {
               if(!flag && s[index] < s[j])
               {
                   index = j;
                   flag = true;
                   continue;
               }
               if(flag && s[j] < s[index] && s[j] > s[i])
                   index = j;
           }
           if(index != i)
           {
               swap(s[index], s[i]);
               sort(s.begin() + i + 1, s.end());
               break;
           }
        }
        if(i == -1)
            return -1;
        else
        {
            int ans = atoi(s.c_str());
            if(ans <= n)
                return -1;
            else
                return ans;
        }
    }
};

int main()
{
    int n  = 1999999999;
    Solution obj;
    cout<<obj.nextGreaterElement(n);
	return 0;
}

