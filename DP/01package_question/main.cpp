/*************************************************
question:
    famous 0-1 package question
    so I don't describe it

example:
    input:
        4 5
        3 2 2 1 4 3 2 2
    output:
        7
*************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::max;

int res(const vector<pair<int,int>> &vec,int _size,int index,int weight);

int main()
{
    int weight;
    int _size;
    vector<pair<int,int>> things;

    cin>>_size>>weight;
    for(int i = 0; i != _size; ++i)
    {
        int weight;
        int value;
        cin>>value>>weight;
        things.push_back(pair<int,int>{value,weight});
    }

    cout<<res(things,_size,0,weight);
    return 0;
}


/**
 *  recursion of every situation about put it or not put it
 *  it's complexity analysis is about O(2^n)
 */
int res(const vector<pair<int,int>> &vec,int _size,int index,int weight)
{
    if(index == _size)
        return 0;
    else if(weight < vec[index].second)
        return res(vec,_size,index + 1,weight);
    else
        return max(res(vec,_size,index + 1,weight),res(vec,_size,index + 1,weight - vec[index].second) + vec[index].first);
}

/**
 * recursion of every situation about put it or not put it,
 * but it use an 2D array to story data that ever know
 * so it's complexity analysis is about O(n * m)
 */
int improve_res(const vector<pair<int,int>> &vec,vector<vector<int>> &table,int _size,int index,int weight)
{
    if(table[index][weight] != -1)
        return table[index][weight];

    int rec = 0;
    if(index == _size)
        rec = 0;
    else if(weight < vec[index].second)
        rec =  res(vec,_size,index + 1,weight);
    else
        rec =  max(res(vec,_size,index + 1,weight),res(vec,_size,index + 1,weight - vec[index].second) + vec[index].first);

    table[index][weight] = rec;
    return table[index][weight];
}

/**
 *  complete 0-1 package question
 *  every thing you can number of one to n
 *  it take O(n * m)
 */
int solv(const vector<pair<int>> &vec,int _size,int weight)
{
    vector<vector<int>> table(_size + 1,vector<int>(weight + 1));

    for(int i = 0; i != _size; ++i)
    {
        for(int j = 0; j != weight; ++j)
        {
            if(j < vec[i].second)
                table[i + 1][j] = table[i][j];
            else
                table[i + 1][j] = max(table[i][j],table[i + 1][j - vec[i].second] + vec[i].first);
        }
    }
    cout<<table[_size][weight];
}
