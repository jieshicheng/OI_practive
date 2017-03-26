#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        while(cur && cur->next)
        {
            if(cur->next->val == cur->val)
            {
                cur->next = cur->next->next;

            }
            else
                cur = cur->next;
        }
        return head;
    }
};

int main()
{
	return 0;
}
