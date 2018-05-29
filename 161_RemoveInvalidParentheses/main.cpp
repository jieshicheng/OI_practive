#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <unordered_set>

using namespace std;



class Solution {
public:
    vector<string> getAns(vector<char> &parathes) {
        string str(parathes.begin(), parathes.end());
        vector<string> ans;

        queue<string> que;
        que.push(str);

        unordered_set<string> st;
        st.insert(str);

        bool found = false;

        while( !que.empty() ) {
            string temp = que.front();
            que.pop();
            if( checkParathes(temp) ) {
                ans.push_back(temp);
                found = true;
            }
            if( found )
                continue;
            for( int i = 0; i != temp.size(); ++i ) {
                if( temp[i] != '(' && temp[i] != ')' )
                    continue;
                string newStr = temp.substr(0, i) + temp.substr(i + 1);
                if( st.find(newStr) == st.end() ) {
                    que.push(newStr);
                    st.insert(newStr);
                }
            }
        
        }
        return ans;
    }

    bool checkParathes(const string &str) {
        int ans = 0;
        for( int i = 0; i != str.size(); ++i ) {
            if( ans < 0 ) {
                return false;
            }
            if( str[i] == '(' ) {
                ans++;
            }
            else if( str[i] == ')' ) {
                ans--;
            }
        }
        return ans == 0;
        
    }
};

int main() {
    Solution solv;
    string s = "(())())";
    vector<char> str(s.begin(), s.end());
    auto ans = solv.getAns(str);
	for_each(ans.begin(), ans.end(), [](string &s) { cout << s << endl; });
    return 0;
}

