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
	bool hasCycle(ListNode *head)
	{
		if(head && head->next)
		{
			bool flag = false;
			ListNode *pre = head;
			ListNode *suf = head->next;
			while(suf)
			{
				if(suf == pre)
					return true;
				else
				{
					if(flag)
					{
						flag = !flag;
						pre = pre->next;
					}
					suf = suf->next;
				}
			}
			return false;
		}
		return false;
	}
};

int main()
{
	return 0;
}
