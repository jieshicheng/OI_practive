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
    vector<int> getPrime(int limit) {
        vector<bool> used(limit + 1, true);
        vector<int> prime;
        for( int i = 2; i <= limit; ++i ) {
            if( used[i] ) {
                prime.push_back(i);
                for( int k = 2; k * i <= limit; ++k ) {
                    used[k * i] = false;
                }
            }
        }
        return prime;
    }

    int calNumber(int n, int m) {
        vector<int> prime = getPrime(sqrt(m + 0.5));
        vector<bool> nums(m - n + 1, true);
        for( int i = 0; i != prime.size(); ++i ) {
            int temp = prime[i] * prime[i];
            for( int k = 1; ; ++k ) {
                if( k * temp <= m && k * temp >= n )
                    nums[k * temp - n] = false;
                else if( k * temp > m )
                    break;
            }
        }
        int ans = 0;
        for( int i = 0; i != nums.size(); ++i ) {
            if( nums[i] )
                ans++;
        }
        return ans;
    }
};

int main() {
    Solution solv;
    cout << solv.calNumber(10, 100000) << endl;
	return 0;
}

