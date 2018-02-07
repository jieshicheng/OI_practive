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
    int findSubstringInWraproundString(string p) {
        vector<int> flag(26, 0);
        int length = 0;
        for( int i = 0; i != p.size(); ++i ) {
            if( i > 0 && p[i] == p[i - 1] + 1 || p[i] == 'a' && p[i - 1] == 'z' )
                length += 1;
            else
                length = 1;
            flag[p[i] - 'a'] = max(flag[p[i] - 'a'], length);
        }
        long long sum = 0;
        for( int i = 0; i != 26; ++i )
            sum += flag[i];
        return sum;
    }
};

int main() {
    Solution solv;
    cout << solv.findSubstringInWraproundString("yhxtdobyly") << endl;
	return 0;
}

