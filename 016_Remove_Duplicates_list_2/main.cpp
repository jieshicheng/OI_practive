#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        bool flag = false;
        auto cur = head;
        ListNode *pre = NULL;
        while(cur && cur->next)
        {
            flag = false;
            while(cur->next && cur->val == cur->next->val)
            {
                flag = true;
                cur->next = cur->next->next;
            }
            if(flag)
            {
                if(pre == NULL)
                    if(head == cur)
                    {
                           head = head->next;
                           cur = head;
                    }
                    else
                        cur = cur->next;
                else
                {
                    pre -> next = cur->next;
                    cur = cur->next;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
	return 0;
}
