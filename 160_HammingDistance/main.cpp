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
    int hammingDistance(int x, int y) {
        int ans = 0;
        unsigned int _x = static_cast<unsigned int>(x);
        unsigned int _y = static_cast<unsigned int>(y);
        for( int i = 0; i != 32; ++i ) {
            int x1 = _x % 2;
            int y1 = _y % 2;
            if( x1 != y1 )
                ans++;
            _x /= 2;
            _y /= 2;
        }
        return ans;
    }	
};

int main() {
	return 0;
}

