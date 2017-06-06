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

    //ways 1
    int findIndex(int deep, int number) {
        vector<bool> flag(pow(2, deep - 1) - 1, false);
        int k;

        for( int i = 0; i != number; ++i ) {
            k = 1;
            while( true ) {
                flag[k] = !flag[k];
                k = flag[k] ? k * 2 : k * 2 + 1;
                if( k >= flag.size() )
                    break;
            }
        }
        return k;
    }

    //ways2
    int findLeaf(int deep, int number) {
        int k = 1;
        for( int i = 0; i != deep - 1; ++i) {
            if( number % 2) {
                k = k * 2;
                number = ( number + 1 ) / 2;
            }else {
                k = k * 2 + 1;
                number /= 2;
            }
        }
        return k;
    }

};

int main() {
	Solution obj;
    cout << obj.findIndex(3, 1) << endl;
    cout << obj.findLeaf(4, 2) << endl;   
    return 0;
}

