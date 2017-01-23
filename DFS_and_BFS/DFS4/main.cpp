/*****************************************

question:
    POJ 3187
    Backward Digit Sums
@author     jieshi
@date       5 Jan 2017

******************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::min_element;
using std::cout;
using std::cin;
using std::vector;

class compare
{
    public:
        bool operator ()(const vector<int> &lhs,const vector<int> &rhs)
        {
        if( lhs.size() < rhs.size() )
        {
            return true;
        }
        else if( lhs.size() == rhs.size() )
        {
            for(int i = 0; i != lhs.size(); ++i)
            {
                if(lhs[i] < rhs[i])
                    return true;
                if(lhs[i] > rhs[i])
                    return false;
            }
        }
        else
            return false;
        }
};

int askSum(vector<int> vec)
{
    int size = vec.size();
    while( size > 1 )
    {
        int i;
        for(i = 0; i != size - 1; ++i)
        {
            int temp = vec[i] + vec[i + 1];
            vec[i] = temp;
        }
        --size;
    }
    return vec[0];

}

void DFS(vector<int> vec,int localDeep,int number,vector<bool> &used,vector<vector<int>> &ans,int goals)
{
    if(localDeep == number)
    {
        if( goals == askSum(vec) )
        {
            ans.push_back(vec);
        }
        return ;
    }
    
    for(int i = 1; i <= number; ++i)
    {
        if( !used[i] )
        {
            used[i] = true;
            vec.push_back(i);
            DFS(vec,localDeep + 1,number,used,ans,goals);
            vec.erase(vec.end() - 1);
            used[i] = false;
        }
    }
    return ;
}



int main()
{
    int number,goals;
    cin>>number>>goals;
    vector<int> vec;
    vector<bool> used(number + 1,false);
    vector<vector<int>> ans;

    DFS(vec,0,number,used,ans,goals);

    auto q = *min_element(ans.begin(),ans.end(),compare());
    for(const auto &r : q)
        cout<<r<<" ";
    return 0;
}
