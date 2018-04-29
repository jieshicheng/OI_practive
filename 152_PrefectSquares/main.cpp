#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <cmath>

using namespace std;



class Solution {
public:
int numSquares(int n) {
        vector<int> vec(n + 1, 0x3fffffff);
        return numsquares(n, vec);
    }
    
    int numsquares(int n, vector<int> &vec) {
        if( vec[n] != 0x3fffffff )
            return vec[n];
        int times = sqrt(n);
        if( times * times == n ) {
            vec[n] = 1;
            return 1;
        }
        while( times > 1 ) {
            vec[n] = min(1 + numsquares(n - times * times, vec), vec[n]);
            times--;
        }
        return vec[n] < n ? vec[n] : n;
    }	
};

int main() {
    return 0;
}

