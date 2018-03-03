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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int step = 0;
        ListNode *ans = nullptr;
        ListNode *iter;
        while( l1 || l2 ) {
            int temp = step;
            if( l1 ) {
                temp += l1->val;
                l1 = l1->next;
            }
            if( l2 ) {
                temp += l2->val;
                l2 = l2->next;
            }
            step = temp / 10;
            ListNode *node = new ListNode(temp % 10);
            if( ans == nullptr )
                ans = iter = node;
            else {
                ans->next = node;
                ans = ans->next;
            }
        }
        if( step != 0 )
            ans->next = new ListNode(step);
        return iter;
    }
};

int main() {
	return 0;
}

