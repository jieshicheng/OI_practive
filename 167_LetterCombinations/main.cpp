#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        vector<vector<char>> letters(10);
        letters[2] = {'a', 'b', 'c'};
        letters[3] = {'d', 'e', 'f'};
        letters[4] = {'g', 'h', 'i'};
        letters[5] = {'j', 'k', 'l'};
        letters[6] = {'m', 'n', 'o'};
        letters[7] = {'s', 'r', 'p', 'q'};
        letters[8] = {'t', 'u', 'v'};
        letters[9] = {'z', 'y', 'x', 'w'};

        vector<string> ans;
        dfs(letters, digits, ans, 0, "");
        return ans;
    }

    void dfs(const vector<vector<char>> &letters, const string &digits, vector<string> &ans, 
             int index, string temp) {
        if (index == digits.length()) {
            ans.push_back(temp);
            return ;
        }
        int num = digits[index] - '0';
        for (char ch : letters[num]) {
            dfs(letters, digits, ans, index + 1, temp + ch);
        }
    }
};

int main() {
    Solution solv;
    auto ans = solv.letterCombinations("23");
    for_each(ans.begin(), ans.end(), [](const string &s) {
        cout << s << endl; 
    });
	return 0;
}

