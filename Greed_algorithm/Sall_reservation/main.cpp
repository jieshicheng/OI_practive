#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>

using std::vector;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::priority_queue;

class compare
{
    public:
        bool operator ()(const pair<int,int> &lhs,const pair<int,int> &rhs)
        {
            return lhs.first > rhs.first;
        }
};

int main()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> que;
    int number;
    cin>>number;
    int beg,ed;
    vector<pair<int,int>> vec;
    for(int i = 0; i != number; ++i)
    {
        cin>>beg>>ed;
        que.push(pair<int,int>(beg,ed));
    }


    while( !que.empty() )
    {
        pair<int,int> temp = que.top();
        que.pop();
        if( vec.empty() )
        {
            vec.push_back(temp);
            cout<<1;
        }
        else
        {
            int maxEnd = temp.first;
            int index = vec.size();
            for(int i = 0; i != vec.size(); ++i)
            {
                if(vec[i].second < maxEnd)
                {
                    maxEnd = vec[i].second;
                    index = i;
                }
            }
            if( index == vec.size() )
            {
                vec.push_back(temp);
                cout<<index + 1;
            }
            else
            {
                vec[index].second = temp.second;
                cout<<index + 1;
            }
        }
    }
    cout<<endl<<vec.size();
    return 0;
}
