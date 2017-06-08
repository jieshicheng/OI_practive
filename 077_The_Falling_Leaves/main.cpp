#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

#define MAXN 100

class Solution {

public:

    void init(int p, vector<int> &leave) {
        int number;
        cin >> number;
        if( number == -1 )
            return;
        leave[p] += number;
        init(p - 1, leave);
        init(p + 1, leave);
    }

    void solvWays() {
        vector<int> leave(MAXN, 0);
        init(MAXN / 2, leave);
        int i = MAXN / 2;
        while( leave[i] != 0 ) 
            --i;
        ++i;
        while( leave[i] != 0 )
            cout << leave[i++] << ' ';
        cout << endl;
    }
};

int main() {
	Solution obj;
    obj.solvWays();
    return 0;
}

