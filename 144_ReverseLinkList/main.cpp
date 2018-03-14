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
    ListNode* reverseList(ListNode* head) {
        if( !head || !head->next )
            return head;
        ListNode *pre = nullptr, *mid = head, *last = head->next;
        while( last ) {
            mid->next = pre;
            pre = mid;
            mid = last;
            last = last->next;
        }
        mid->next = pre;
        return mid;
    }	
};

int main() {
	return 0;
}

