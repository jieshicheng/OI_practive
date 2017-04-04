#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(!head)
            return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p1 = newHead;
        ListNode *p2 = head;
        while(p2 && p2->next)
        {
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return newHead->next;
    }
};

int main()
{
	return 0;
}

