#include <iostream>
#include <vector>

using namespace std;

void getInput(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
    	cin >> arr[i];
    }
}

bool getBitIsOne(int i, int index) {
    return (i >> index) % 2 == 1;
}

int getXorSum(const vector<int> &arr) {
    int xorsum = arr[0];
    for_each(arr.begin() + 1, arr.end(), [&](int i) {
        xorsum ^= i;
    });
    return xorsum;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);

    getInput(arr);

    int xorsum = getXorSum(arr);

    int index = 0;
    while (xorsum != 0) {
    	if ((xorsum >> index) % 2 == 1) {
	        break;
	    }
    }

    vector<int> left;
    vector<int> right;
    for_each(arr.begin(), arr.end(), [&](int i) {
		if (getBitIsOne(i, index)) {
            left.push_back(i);
        }
        else {
            right.push_back(i);
        }
    });

    cout << getXorSum(left) << "\t" << getXorSum(right) << endl;

    return 0;
}

