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
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool isNumber(vector<int> divd) {
        if( divd.size() <= 1 )
            return true;
        divd[1] /= gcd(divd[0], divd[1]);
        if( divd.size() >= 2 ) {
            for( int i = 2; i != divd.size(); ++i ) {
                divd[1] /= gcd(divd[i], divd[1]);
            }
        }
        return divd[1] == 1;
    }
};

int main() {
	return 0;
}

