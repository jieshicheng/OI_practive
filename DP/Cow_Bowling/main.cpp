#include <iostream>
#include <vector>
#include <algorithm>

using std::max_element;
using std::max;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int rows;
    cin>>rows;
    int temp;
    vector<vector<int>> vec(rows);
    for(int i = 0; i != rows; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            cin>>temp;
            vec[i].push_back(temp);
        }
        if(i == 0)
            continue;
        else
        {
            for(int k = 0; k != vec[i].size(); ++k)
            {
                int _max = vec[i][k];
                if(k - 1 >= 0)
                    _max = vec[i][k] + vec[i - 1][k - 1];
                if(k < vec[i - 1].size())
                    _max = max(_max,vec[i][k] + vec[i - 1][k]);
                vec[i][k] = _max;
            }
        }
    }
    cout<<*max_element(&vec[rows - 1][0],&vec[rows - 1][rows - 1]);
    return 0;
}
