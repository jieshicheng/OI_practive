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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if( nums1.size() > nums2.size() ) {
            auto temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int sizeA = nums1.size(), sizeB = nums2.size();
        int begin = 0, end = sizeA, halfLen = (sizeA + sizeB + 1) / 2;
        while( begin <= end ) {
            int i = (begin + end) / 2;
            int j = halfLen - i;
            if( i > 0 && nums1[i - 1] > nums2[j] ) {
                end = i - 1;
            }
            else if( j > 0 && i < sizeA && nums1[i] < nums2[j - 1] ) {
                begin = i + 1;
            }
            else {
                int left;
                if( i == 0 )
                    left = nums2[j - 1];
                else if( j == 0 )
                    left = nums1[i - 1];
                else
                    left = max(nums1[i - 1], nums2[j - 1]);
                if( (sizeA + sizeB) % 2 == 1 )
                    return left;

                int right;
                if( i == sizeA )
                    right = nums2[j];
                else if( j == sizeB )
                    right = nums1[i];
                else
                    right = min(nums1[i], nums2[j]);
                return (left + right) / 2.0;
            }

        }
    }


};

int main() {
	return 0;
}

