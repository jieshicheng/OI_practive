#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class myCompare
{
public:
    bool operator ()(Interval &lhs, Interval &rhs)
    {
        return lhs.end < rhs.end;
    }
};

class Solution
{
public:
    int eraseOverlapIntervals(vector<Interval> &intervals)
    {
        size_t size = intervals.size();
        if(size < 1)
            return 0;
        sort(intervals.begin(), intervals.end(), myCompare());
        int bord = intervals.begin()->start;
        int ans = 0;
        for(const auto &r : intervals)
        {
            if(r.start < bord)
                ++ans;
            else
                bord = r.end;
        }
        return ans;
    }
};

int main()
{
	return 0;
}

