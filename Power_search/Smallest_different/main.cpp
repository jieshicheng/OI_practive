/***********************************

question:
    POJ 2718
    Smallest Different
@author     jieshi
@date       3 Jan 2017

************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::cin;
using std::vector;

void DFSB(int val,int deep,int deepMaxB,const vector<int> &vec,vector<bool> &used,int valA,int number,vector<int> &ansVec);
void DFSA(int val,int deep,int deepMaxA,int number,const vector<int> &vec,vector<bool> &used,vector<int> &ansVec)
{
    if(deep == deepMaxA)
    {
        int deepMaxB = number - deepMaxA;
        DFSB(0,0,deepMaxB,vec,used,val,number,ansVec);
        return ;
    }


    for(int i = 0; i != number; ++i)
    {
        if(deep == 0 && vec[i] == 0)
            continue;
        if( !used[i] )
        {
            used[i] = true;
            DFSA(val * 10 + vec[i],deep + 1,deepMaxA,number,vec,used,ansVec);
            used[i] = false;
        }
    }
}

void DFSB(int val,int deep,int deepMaxB,const vector<int> &vec,vector<bool> &used,int valA,int number,vector<int> &ansVec)
{
    static int ans = 999999;
    if(deep == deepMaxB)
    {
        ans = min(ans,max(val,valA) - min(val,valA));
        ansVec.push_back(ans);
        return ;
    }

    for(int i = 0; i != number; ++i)
    {
        if(deep == 0 && vec[i] == 0)
            continue;
        if( !used[i] )
        {
            used[i] = true;
            DFSB(val * 10 + vec[i],deep + 1,deepMaxB,vec,used,valA,number,ansVec);
            used[i] = false;
        }
    }
}


int main()
{
    int number;
    cin>>number;
    vector<int> vec;
    for(int i = 0; i != number; ++i)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    vector<bool> used(number,false);
    int deepMaxA = number >> 1;
    vector<int> ansVec;

    DFSA(0,0,deepMaxA,number,vec,used,ansVec);
    cout<<*min_element(ansVec.begin(),ansVec.end());
    return 0;
}
