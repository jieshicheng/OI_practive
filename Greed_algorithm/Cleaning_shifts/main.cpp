/***************************************

question:
    POJ 2376
    Cleaning Shifts
@author     jieshi
@date       6 Jan 2017

**************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::cout;
using std::cin;
using std::vector;

class Cow
{
    public:
        int beg;
        int ed;
        int weight;

        Cow(int b,int e,int w) : beg(b),ed(e),weight(w) { }
};


int main()
{
    int numberOfCow,days;
    cin>>numberOfCow>>days;

    vector<Cow> vec;
    for(int i = 0; i != numberOfCow; ++i)
    {
        int b,e,w;
        cin>>b>>e;
        w = e - b;
        vec.push_back(Cow(b,e,w));
    }

    int ans = 0;
    int nowTime = 1;
    while(nowTime < days)
    {
        int max = nowTime;
        for(int i = 0; i != numberOfCow; ++i)
        {
            if(vec[i].beg <= nowTime && vec[i].ed > max)
            {
                max = vec[i].ed;
            }
        }
        if(max == nowTime)
        {
            cout<<-1;
            break;
        }
        ++ans;
        nowTime = max;
    }
    if(nowTime >= days)
        cout<<ans;
    return 0;
}
