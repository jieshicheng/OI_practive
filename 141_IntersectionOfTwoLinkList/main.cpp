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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( headA == nullptr || headB == nullptr )
            return nullptr;
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        while( iterA != iterB ) {
            iterA = iterA == nullptr ? headB : iterA->next;
            iterB = iterB == nullptr ? headA : iterB->next;
        }
        return iterA;
    }
};

int main() {
	return 0;
}

