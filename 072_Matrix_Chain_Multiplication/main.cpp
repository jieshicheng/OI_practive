#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {

public:
    int calculateTimes() {
        int numberOfMatrix;
        cin >> numberOfMatrix;
        map<char, pair<int, int>> mp;
        for(int i = 0; i != numberOfMatrix; ++i) {
            char name;
            int row, col;
            cin >> name;
            cin >> row >> col;
            mp[name] = {row, col};
        }
        string s;
        cin >> s;
        stack<pair<int, int>> stk;
        int ans = 0;
        for(const auto &c : s) {
            if( c == ')' ) {
                pair<int, int> m2 = stk.top();
                stk.pop();
                pair<int, int> m1 = stk.top();
                stk.pop();
                if( m1.second != m2.first ) {
                    cout << "error" << endl;
                    return -1;
                }
                ans += m1.first * m1.second * m2.second;
                stk.push({m1.first, m2.second});
            }
            else if( c != '(' ) {
                stk.push(mp[c]);
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.calculateTimes() << endl;
    
    return 0;
}
