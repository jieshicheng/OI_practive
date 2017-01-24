/******************************************
question:
    straight line has n point,x's position is x[i]
    given a area R.you should mark n point,make it cover more point

example:
    input:
        6 10
        1 7 15 20 30 50
    output:
        3
        (reason:only mark 7,20,50.can cover all point)

******************************************/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int solv(const vector<int> &vec,const int &_size,const int &range);

int main()
{
    vector<int> vec;             //x[] array
    int number;                 //number of n
    int range;                    //range R

    //initialization
    cin>>number>>range;
    for(int i = 0; i != number; ++i)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }

    cout<<solv(vec,number,range);

    return 0;
}

/**
 *  calculate how many point at least mark
 *  vec     x[] array
 *  _size   array's size
 *  range   range of cover
 */
int solv(const vector<int> &vec,const int &_size,const int &range)
{
    int answer = 0;
    int index = 0;
    while(index < _size)
    {
        int point = 1;
        while(index + point <= _size && vec[index] + range >= vec[index + point])
        {
            ++point;
        }
        index = index + point - 1;
        ++answer;
        point = 1;
        while(index + point <= _size && vec[index] + range >= vec[index + point])
        {
            ++point;
        }
        index = point + index;
    }
    return answer;
}
