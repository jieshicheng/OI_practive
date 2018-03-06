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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sortVec;
        vector<vector<string>> ans;
        if( strs.size() == 0 ) 
            return ans;
        ans.push_back({strs[0]});
        sort(strs[0].begin(), strs[0].end());
        sortVec.push_back(strs[0]);
        for( int i = 1; i != strs.size(); ++i ) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            int j;
            for( j = 0; j != sortVec.size(); ++j ) {
                if( temp == sortVec[j] ) {
                    ans[j].push_back(strs[i]);
                    break;
                }
            }
            if( j == sortVec.size() ) {
                ans.push_back({strs[i]});
                sortVec.push_back(temp);
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}

