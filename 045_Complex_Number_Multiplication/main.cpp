#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void reserver(string &s)
    {
        int size = s.size();
        for(int i = 0; i < size / 2; ++i)
        {
            char temp = s[i];
            s[i] = s[size - 1 - i];
            s[size - 1 - i] = temp;
        }
    }


    string complexNumberMultiply(string a, string b)
    {
        vector<bool> symbol(4, false);
        vector<int> number(4, 0);
        int i = 0;
        int j = 0;
        if(a[0] == '-')
        {
            symbol[0] = true;
            i++;
        }
        if(b[0] == '-')
        {
            symbol[2] = true;
            j++;
        }
        for(; a[i] != '+'; ++i)
        {
            number[0] *= 10;
            number[0] += (a[i] - 48);
        }
        for(; b[j] != '+'; ++j)
        {
            number[2] *= 10;
            number[2] += (b[j] - 48);
        }
        ++i, ++j;
        if(a[i] == '-')
        {
            i++;
            symbol[1] = true;
        }
        if(b[j] == '-')
        {
            j++;
            symbol[3] = true;
        }
        for(; a[i] != 'i'; ++i)
        {
            number[1] *= 10;
            number[1] += (a[i] - 48);
        }
        for(; b[j] != 'i'; ++j)
        {
            number[3] *= 10;
            number[3] += (b[j] - 48);
        }
        for(i = 0; i != 4; ++i)
        {
            if(symbol[i] == true)
                number[i] = -number[i];
            cout<<number[i]<<endl;
        }

        int q,w,e;
        q = number[0] * number[2];
        w = number[0] * number[3] + number[1] * number[2];
        e = -(number[1] * number[3]);
        q = q + e;
        cout<<q<<" "<<w<<endl;


        char s[10];
        i = 0;
        bool flag1 = false;
        bool flag2 = false;
        if(q < 0)
        {
            flag1 = true;
            q = -q;
        }
        while(q)
        {
            s[i++] = (q % 10) + 48;
            q /= 10;
        }
        if(i == 0)
            s[i++] = 48;
        s[i] = '\0';
        string str(s);
        cout<<str<<endl;
        reserver(str);
        
        
        
        i = 0;
        if(w < 0)
        {
            flag2 = true;
            w = -w;
        }
        while(w)
        {
            s[i++] = (w % 10) + 48;
            w /= 10;
        }
        if(i == 0)
            s[i++] = 48;
        s[i] = '\0';
        string str2(s);
        cout<<str2<<endl;
        reserver(str2);
        string ans;
        if(flag1)
            ans.append("-");
        ans.append(str).append("+");
        if(flag2)
            ans.append("-");
        ans.append(str2);
        ans.append("i");
        return ans;

    }
};

int main()
{
    string s1("78+-76i"), s2("-86+72i");
    Solution obj;
    cout<<obj.complexNumberMultiply(s1, s2)<<endl;
	return 0;
}

