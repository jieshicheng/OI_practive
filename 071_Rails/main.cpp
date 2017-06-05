#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {

public:
    bool checkTrue(vector<int> &input, vector<int> &output) {
        stack<int> stk;
        int A = 0, B = 0;
        while( B < output.size() ) {
            if( input[A] == output[B] ) {
                ++A;
                ++B;
            }
            else if( !stk.empty() && stk.top() == output[B] ) {
                stk.pop();
                ++B;
            }
            else if( A < input.size() ) {
                stk.push(input[A++]);
            }
            else {
                return false;
            }

        }
        return true;
    }
};

int main() {
	vector<int> input{5,4,1,2,3};
    vector<int> output{1,2,3,4,5};

    Solution obj;
    cout << obj.checkTrue(input, output) << endl;
    
    return 0;
}

