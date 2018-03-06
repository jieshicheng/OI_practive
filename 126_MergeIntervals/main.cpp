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
	vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if( intervals.size() == 0 )
            return ans;
        sort(intervals.begin(), intervals.end(), [](const Interval &left, const Interval &right){
            if( left.start < right.start )
                return true;
            else if( left.start == right.start && left.end < right.end )
                return true;
            else
                return false;
        });
        Interval temp(intervals[0].start, intervals[0].end);
        for( int i = 1; i != intervals.size(); ++i ) {
            if( intervals[i].start <= temp.end )
                temp.end = max(temp.end, intervals[i].end);
            else {
                ans.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main() {
	return 0;
}

