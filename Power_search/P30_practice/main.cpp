/**********************
question:
    give n,k;
    n      how much about array
    k      an integer
    give an array {a1,a2,a3 .... an};
    judge whether there is number of n,let them sum equal k;

example:
    input
        6
        4 2 1 5 6 7
        11
    output
        Yes
************************/

#include <iostream>
#include <vector>

using namespace std;

bool seek_sum(const vector<int> &vec,const int &pos,const int &goal,const int &sum);

int main()
{
    int number;               //this is n
    vector<int> vec;               //this is array
    int goal;                  //this is k
    int temp;
    int sum = 0;

    //get data
    cin>>number;
    for(int i = 0; i != number; ++i)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>goal;

    //if seek_sum return true ... then ...
    if( seek_sum(vec,0,goal,sum) )
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}

/**
 *  recursive call,if sum equal goal,return true,then return false
 *  vec     an array
 *  pos     index of array
 *  goal    k
 *  sum     result
 */
bool seek_sum(const vector<int> &vec,const int &pos,const int &goal,const int &sum)
{
    if( sum == goal )
        return true;
    if( sum > goal )
        return false;

    if(vec.begin() + pos != vec.end())
    {
        return seek_sum(vec,pos + 1,goal,sum + vec[pos]) || seek_sum(vec,pos + 1,goal,sum);
    }

    return false;
}
