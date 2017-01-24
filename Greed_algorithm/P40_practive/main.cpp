/******************************************
question:
    there is N task wait to do;
    for every task i ,At s[i] star,end at t[i];
    you can choose n task,let  n max;

example:
    input:
        5
        1 2 4 6 8
        3 5 7 9 10
    output:
        3
        (reason:choose 1 , 3 and 5)
*****************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::pair;


int solv(const vector<int> &_star,const vector<int> &_end,const int &size);

int main()
{
    int number;          //number of task
    vector<int> star_time;         //array of star time
    vector<int> end_time;              //array of end time

    //initialization
    cin>>number;
    for(int i = 0; i != number; ++i)
    {
        int temp;
        cin>>temp;
        star_time.push_back(temp);
    }
    for(int i = 0; i != number; ++i)
    {
        int temp;
        cin>>temp;
        end_time.push_back(temp);
    }

    cout<<solv(star_time,end_time,number);

    return 0;
}

/**
 *  compare and select task to do
 *  _star   star time array
 *  _end    end time array
 *  size    number of task
 */
int solv(const vector<int> &_star,const vector<int> &_end,const int &size)
{
    vector<pair<int,int>> vec;
    int temp = 0;
    int answer = 0;

    for(int i = 0; i != size; ++i)
        vec.push_back(pair<int,int>{_end[i],_star[i]});

    sort( vec.begin(),vec.end(),[](const pair<int,int> &lhs,const pair<int,int> &rhs) { return lhs.first < rhs.first; } );

    for(int i = 0; i != size; ++i)
    {
        if(temp < vec[i].second)
        {
            ++answer;
            temp = vec[i].first;
        }
    }

    return answer;
}
