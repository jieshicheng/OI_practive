#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    void reserve(string &s)
    {
        size_t size = s.size();
        for(size_t i = 0; i < size / 2; ++i)
        {
            char temp = s[i];
            s[i] = s[size - 1 - i];
            s[size - i - 1] = temp;
        }
    }

    string conv(int num)
    {
        char buf[5];
        int i = 0;
        int temp;
        while(num)
        {
            temp = num % 10;
            buf[i++] = temp + 48;
            num = num / 10;
        }
        buf[i] = '\0';
        string s(buf);
        cout<<s<<endl;
        reserve(s);
        cout<<s<<endl;
        return s;
    }


    string optimalDivision(vector<int> &nums)
    {
        size_t size = nums.size();
        if(size == 0)
            return string("");
        if(size == 1)
            return string(conv(nums[0]));
        if(size == 2)
        {
            string s;
            s = s.append(conv(nums[0])).append("/").append(conv(nums[1]));
            return s;
        }
        string s(conv(nums[0]));
        s = s + "/(";
        for(size_t i = 1; i != size - 1; ++i)
        {
            s = s.append(conv(nums[i])).append("/");
        }
        s = s.append(conv(nums[size - 1])).append(")");
        return s;
    }
};

int main()
{
    vector<int> vec{1000,100,10,4};
	Solution obj;
    cout<<obj.optimalDivision(vec)<<endl;
    return 0;
}

