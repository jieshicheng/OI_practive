/****************************************
question:
    LCS longest common subsequence
    it famous,so I don't describe it

example:
    input:
        4 4
        abcd
        becd
    output:
        3
****************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::max;

void solv(const string &s1,const string &s2,vector<vector<int>> &table,int size1,int size2);

int main()
{
    int size1;
    int size2;
    string str1;
    string str2;
    char ch;

    cin>>size1>>size2;
    cin.get(ch);
    getline(cin,str1);
    getline(cin,str2);

    vector<vector<int>> table(size1 + 1,vector<int>(size2 + 1));

    solv(str1,str2,table,size1,size2);

    cout<<table[size1][size2];
    return 0;
}

/**
 *  DP.2D array solve it
 *  it complexity analysis is O(n * m)
 */
void solv(const string &s1,const string &s2,vector<vector<int>> &table,int size1,int size2)
{
    for(int i = 0; i != size1; ++i)
    {
        for(int j = 0; j != size2; ++j)
        {
            if(s1[i] == s2[j])
                table[i + 1][j + 1] = table[i][j] + 1;
            else
                table[i + 1][j + 1] = max(table[i + 1][j],table[i][j + 1]);
        }
    }
}
