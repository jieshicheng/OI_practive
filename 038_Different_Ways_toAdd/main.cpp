#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    map<string, vector<int>> mem;

    vector<int> diffWaysToCompute(string input)
    {
        int size = input.size();
        vector<int> result;
        for(int i = 0; i != size; ++i)
        {
            if(c < '0' || c > '9')
            {
                string strLeft = input.substr(0, i);
                string strRight = input.substr(i + 1);
                vector<int> left;
                vector<int> right;
                if(mem.find(strLeft) != mem.end())
                    left = mem[strLeft];
                else
                    left = diffWaysToCompute(input.substr(0, i));
                if(mem.find(strRight) != mem.end())
                    right = mem[strRight];
                else
                    right = diffWaysToCompute(input.substr(i + 1));
                for(int j = 0; j != left.size(); ++j)
                {
                    for(int k = 0; k != right.size(); ++k)
                    {
                        if(c == '+')
                            result.push_back(left[j] + right[k]);
                        else if(c == '-')
                            result.push_back(left[j] - right[k]);
                        else if(c == '*')
                            result.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if(result.empty())
            result.push_back(stoi(input));
        mem[input] = result;
        return result;
    }
};

int main()
{
	return 0;
}

