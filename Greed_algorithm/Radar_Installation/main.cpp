#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using std::sqrt;
using std::pair;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

void check(vector<pair<float,float>> &vec,const pair<float,float> &postion);

int main()
{
    int number,radius;
    cin>>number>>radius;
    radius = radius * radius;
    int x,y;
    vector<pair<float,float>> vec;
    for(int i = 0; i != number; ++i)
    {
        cin>>x>>y;
        float x_range = sqrt(radius - y * y);
        cout<<x_range<<endl;
        check(vec,pair<float,float>(x - x_range,x + x_range));
    }

    cout<<vec.size();
    return 0;
}

void check(vector<pair<float,float>> &vec,const pair<float,float> &postion)
{
    if( vec.empty() )
        vec.push_back(postion);
    else
    {
        for(int i = 0; i != vec.size(); ++i)
        {
            if( vec[i].first <= postion.first && vec[i].second >= postion.second )
            {
                vec[i].first = postion.first;
                vec[i].second = postion.second;
                break;
            }
            else if(postion.first <= vec[i].first && postion.second >= vec[i].second)
            {
                break;
            }
            else if(postion.first <= vec[i].second && postion.second >= vec[i].second)
            {
                vec[i].first = postion.first;
                break;
            }
            else if(vec[i].first <= postion.second && vec[i].second >= postion.second)
            {
                vec[i].second = postion.second;
                break;
            }
            else
            {
                vec.push_back(postion);
                break;
            }
        }
    }
}
