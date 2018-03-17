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
    bool isPalindrome(ListNode* head) {
        if( !head || !head->next )
            return true;
        if( !head->next->next )
            return head->val == head->next->val;
        
        ListNode *slow, *fast;
        slow = fast = head;
        while( slow && fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if( fast ) {
            ListNode *temp = slow->next;
            reverse(head, slow->next);
            slow = slow->next;
            while( temp && slow ) {
                if( temp->val != slow->val )
                    return false;
                temp = temp->next;
                slow = slow->next;
            }
            return true;
        }
        else {
            ListNode *temp = reverse(head, slow);
            while( temp && slow ) {
                if( temp->val != slow->val )
                    return false;
                temp = temp->next;
                slow = slow->next;
            }
            return true;
        }
    }
    
    ListNode *reverse(ListNode *head, ListNode *end) {
        ListNode *pre, *mid, *last;
        pre = nullptr;
        mid = head;
        last = head->next;
        while( mid != end ) {
            mid->next = pre;
            pre = mid;
            mid = last;
            last = last->next;
        }
        return pre;
    }	
};

int main() {
	return 0;
}

