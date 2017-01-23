/*********************************
question:
    there is a garden has a size of N*M
    after raining,it has a lot of ponding.like this
    ...
    .W.
    ...   call the ponding.

    question is how many ponding in input

example:
    input:
        6 7
        W...W..
        .W..W..
        .W.....
        .......
        ...W...
    output:
        3
*********************************/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int seek_solv(vector<vector<char>> &vec,const int &row,const int &col);
void dfs_vector(vector<vector<char>> &vec,int N,int M,int row,int col);

int main()
{
    vector<vector<char>> vec;             //input 2D array
    int row,col;           //input N,M
    char temp;

    //2D array initializer
    cin>>row>>col;
    for(int i = 0; i != row; ++i)
    {
        vec.push_back(vector<char>());
        for(int j = 0; j != col; ++j)
        {
            cin>>temp;
            vec[i].push_back(temp);
        }
    }

    cout<<seek_solv(vec,row,col);

    return 0;
}

/**
 *  seek every element,if it was 'W',use dfs_search
 *  vec    2D array
 *  row    vec's row
 *  col    vec's col
 */
int seek_solv(vector<vector<char>> &vec,const int &row,const int &col)
{
    int dfs_times = 0;

    for(int i = 0; i != row; ++i)
    {
        for(int j = 0; j != col; ++j)
        {
            if(vec[i][j] == 'W')
            {
                dfs_vector(vec,row,col,i,j);
                ++dfs_times;
            }

        }
    }
    return dfs_times;
}

/**
 *  deep first search given element,until his around no 'W'
 *  vec   2D array
 *  N     vec's row
 *  M     vec'scol
 *  row   given element's row
 *  col   given element's col
 */
void dfs_vector(vector<vector<char>> &vec,int N,int M,int row,int col)
{
    vec[row][col] = '.';

    for(int row_shift = -1; row_shift != 2; ++row_shift)
    {
        for(int col_shift = -1; col_shift != 2; ++col_shift)
        {
            int new_row = row + row_shift;
            int new_col = col + col_shift;
            if(new_row >= 0 && new_row <=N && new_col >= 0 && new_col <= M && vec[new_row][new_col] == 'W')
                dfs_vector(vec,N,M,new_row,new_col);
        }
    }
}
