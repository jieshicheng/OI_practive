#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int p = 24 * 60;

    int calulate(string &lhs, string &rhs)
    {
        int ans = (rhs[0] - lhs[0]) * 10 * 60 +
                  (rhs[1] - lhs[1]) * 60 + 
                  (rhs[3] - lhs[3]) * 10 + 
                  (rhs[4] - lhs[4]);
        ans = abs(ans);
        ans = ans < (p - ans) ? ans : p - ans;
        return ans;
    }

    int findMinDifference(vector<string> &timePoints)
    {
        sort(timePoints.begin(), timePoints.end());
        size_t size = timePoints.size();
        int minimum = 9999;

        for(size_t i = 0 ; i != size - 1; ++i)
        {
            int temp = calulate(timePoints[i], timePoints[i + 1]);
            minimum = min(minimum, temp);
        }
        int temp = calulate(timePoints[size - 1], timePoints[0]);
        minimum = min(temp, minimum);
        return minimum;
    }
};

int main()
{
    vector<string> strs{"23:59", "23:10", "00:52", "11:22"};
    Solution obj;
    cout<<obj.findMinDifference(strs)<<endl;
	return 0;
}

