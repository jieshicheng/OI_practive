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
	ListNode *mergeTwoLists(ListNode *p1, ListNode *p2)
    {   
        if( !p1 )
            return p2;
        if( !p2 )
            return p1;
        ListNode *head;
        if(p1->val < p2->val)
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }
        head->next = nullptr;
        auto p = head;
        while(p1 || p2)
        {
            if( !p1 )
            {
                p->next = p2;
                break;
            }
            if( !p2 )
            {
                p->next = p1;
                break;
            }
            int number = p1->val;
            while(p2->val < number)
            {
                p->next = p2;
                p2 = p2->next;
                p->next->next = nullptr;
                p = p->next;
            }
            if( p2  )
                number = p2->val;
            while(p1->val < number)
            {
                p->next = p1;
                p1 = p1->next;
                p->next->next = nullptr;
                p = p->next;
            }
            if( p1 )
                number = p1->val;
        }
        return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    Solution obj;
    obj.mergeTwoLists(l1, l2);
	return 0;
}
