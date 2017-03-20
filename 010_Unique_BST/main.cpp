#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		vector<long long> vec(n + 1,0);
		vec[1] = 1;
		for(int i = 2; i <= n; ++i)
		{
			vec[i] = vec[i - 1] * (4 * i - 2) / (i + 1);
		}
		return vec[n];
	}
};

int main()
{
	Solution obj;
	cout<<obj.numTrees(19)<<endl;
	return 0;
}
