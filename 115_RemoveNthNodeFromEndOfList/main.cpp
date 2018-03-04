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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head->next == nullptr )
            return nullptr;
        ListNode *first, *second;
        first = second = head;
        while( n-- > 0 ) {
            second = second->next;
        }
        if( second == nullptr )
            return head->next;
        while( second->next ) {
            second = second->next;
            first = first->next;
        }
        if( first->next->next == nullptr )
            first->next = nullptr;
        else
            first->next = first->next->next;
        return head;
        
    }
};

int main() {
	return 0;
}

