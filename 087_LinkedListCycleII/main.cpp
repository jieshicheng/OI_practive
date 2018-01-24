#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct ListNode {
    ListNode(int x) : val(x), next(NULL) {}
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return NULL;
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while( slow != fast ) {
            if( !fast || !fast->next || !fast->next->next )
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while( slow != fast ) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
	return 0;
}

