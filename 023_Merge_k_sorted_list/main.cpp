#include <iostream>
#include <vector>

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
    ListNode *MergeTwo(ListNode *l1, ListNode *l2)
    {
        ListNode *header = NULL, **p;
        for(p = &header; l1 && l2; p = &(*p)->next)
        {
            if(l1->val <= l2->val)
            {
                *p = new ListNode(l1->val);
                l1 = l1->val;
            }
            else
            {
                *p = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        for(ListNode *leave = l1 ? l1 : l2; leave ; leave = leave->next, p = &(*p)->next)
            *p = new ListNode(leave->val);
        return header;
    }

    ListNode *Merge(vector<ListNode *> &lists, int _begin, int _end)
    {
        if(_end == _begin)
            return lists[_end];
        if(_end - _begin == 1)
            return MergeTwo(lists[_begin], lists[_end]);

        int med = (_end - _begin) / 2 + _begin;
        return MergeTwo(Merge(lists, _begin, med), Merge(lists, med + 1, _end));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int s = lists.size();
        if(s == 0)
            return nullptr;
        else
            return Merge(lists, 0, s - 1);
    }
};


int main()
{
	return 0;
}
