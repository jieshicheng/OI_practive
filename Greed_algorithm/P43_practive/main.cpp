/************************************
question:
    I don't want talk about it anymore


***********************************/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;

void solv(const vector<char> &vec,vector<char> &answer,int size);

int main()
{
    int size;
    vector<char> vec;
    vector<char> answer;

    cin>>size;
    for(int i = 0; i != size; ++i)
    {
        char temp;
        cin>>temp;
        vec.push_back(temp);
    }

    solv(vec,answer,size);
    for(const auto &r : answer)
        cout<<r;
    return 0;
}

void solv(const vector<char> &vec,vector<char> &answer,int size)
{
    int i = 0,j = size - 1;

    while( i <= j )
    {
        if(vec[i] < vec[j])
        {
            answer.push_back(vec[i]);
            ++i;
        }
        else
        {
            answer.push_back(vec[j]);
            --j;
        }
    }
}
