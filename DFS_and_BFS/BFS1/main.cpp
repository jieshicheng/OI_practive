/**************************************
question:
    given a maze size of N * M;
    compose by '#' , '.' , 'S' and 'G'
    '.' is path can way to
    '#' is wall can't way to
    'S' is begin
    'G' is end
    ask how many step begin 'S' to 'G'

example:
    input:
        3 5
        #S...
        ...#.
        ....G
    output:
        5
************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void seek_path(vector<vector<char>> &vec,vector<vector<int>> &short_path,const int &row,const int &col,
			  const pair<int,int> &begin_point,const pair<int,int> &end_point);

int main()
{
	int row,col;           //N and M
	vector<vector<char>> vec;          //2D array
	pair<int,int> begin_point;        //staring point's x and y
	pair<int,int> end_point;           //end point's x and y

	//initialization
	cin>>row>>col;
	for(int i = 0; i != row; ++i)
	{
		vec.push_back(vector<char>());
		for(int j = 0; j != col; ++j)
		{
			char temp;
			cin>>temp;
			vec[i].push_back(temp);

			if(temp == 'S')
				begin_point = {i,j};
			if(temp == 'G')
				end_point = {i,j};
		}
	}

	//store step
	//calculate all the point that staring point can arrive need how many step
	vector<vector<int>> short_path(row,vector<int>(col,9999));

    seek_path(vec,short_path,row,col,begin_point,end_point);

	if(short_path[end_point.first][end_point.second] != 9999)
        cout<<short_path[end_point.first][end_point.second];

	return 0;

}

/**
 *  seek path from begin to end
 *  vec             2D array store map
 *  short_path      store all the step that staring point to every point
 *  row             row
 *  col             col
 *  begin_point     staring point
 *  end_point       end point
 */
void seek_path(vector<vector<char>> &vec,vector<vector<int>> &short_path,const int &row,const int &col,
			  const pair<int,int> &begin_point,const pair<int,int> &end_point)
{
	vector<int> row_shift{-1,0,1,0};
	vector<int> col_shift{0,-1,0,1};
	queue<pair<int,int>> que;
	pair<int,int> pos = begin_point;

    short_path[pos.first][pos.second] = 0;
    vec[pos.first][pos.second] = '#';
	while(pos != end_point)
	{
		for(int i = 0; i != 4; ++i)
		{
			if( pos.first + row_shift[i] >= 0 && pos.first + row_shift[i] < row &&
                pos.second + col_shift[i] >= 0 && pos.second + col_shift[i] < col &&
                vec[pos.first + row_shift[i]][pos.second + col_shift[i]] != '#')
			{
				que.push(pair<int,int>{pos.first + row_shift[i],pos.second + col_shift[i]});
				vec[pos.first + row_shift[i]][pos.second + col_shift[i]] = '#';
				short_path[pos.first + row_shift[i]][pos.second + col_shift[i]] = short_path[pos.first][pos.second] + 1;
			}
		}
        if( !que.empty() )
        {
            pos = que.front();
            que.pop();
        }
	}
    return ;
}
