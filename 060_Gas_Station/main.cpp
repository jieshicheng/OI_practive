#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int gasNumber = 0, ans = 0, allGas = 0;
        for(size_t i = 0; i != gas.size(); ++i)
        {
            gasNumber += gas[i] - cost[i];
            if(gasNumber < 0)
            {
                ans = i + 1;
                allGas += gasNumber;
                gasNumber = 0;
            }
        }
        return allGas + gasNumber < 0 ? -1 : ans;
    }
};

int main()
{
	return 0;
}

