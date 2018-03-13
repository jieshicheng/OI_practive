#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if( !head )
            return nullptr;
        ListNode *iter = head;
        int length = 0;
        while( iter ) {
            length++;
            iter = iter->next;
        }
        return mergeSort(head, length);
    }
    
    ListNode *mergeSort(ListNode *node, int length) {
        if( length <= 1 )
            return node;
        int mid = length / 2;
        ListNode *left = node;
        ListNode *right = node;
        for( int i = 0; i < mid - 1; ++i ) {
            right = right->next;
        }
        ListNode *temp = right;
        right = right->next;
        temp->next = nullptr;
        left = mergeSort(left, mid);
        right = mergeSort(right, length - mid);
        ListNode *begin, *iter;
        if( left->val < right->val ) {
            begin = iter = left;
            left = left->next;
        }
        else {
            begin = iter = right;
            right = right->next;
        }
        while( left && right ) {
            if( left->val < right->val ) {
                begin->next = left;
                left = left->next;
            }
            else {
                begin->next = right;
                right = right->next;
            }
            begin = begin->next;
        }
        if( left )
            begin->next = left;
        else if( right )
            begin->next = right;
        return iter;
    }
};



class Solution {
public:
	ListNode* sortList(ListNode* head) {
        if( !head )
            return nullptr;
        ListNode *iter = head;
        int length = 0;
        while( iter ) {
            length++;
            iter = iter->next;
        }
        ListNode *begin = new ListNode(2);
        begin->next = head;
        quickSort(begin, length);
        return begin->next;
    }
    
    void quickSort(ListNode *preNode, int length) {
        if( length <= 1 )
            return ;
        int midVal = preNode->next->val;
        int leftLength = 0;
        ListNode *midIter = preNode->next;
        ListNode *preIter = preNode->next;
        ListNode *iter = preNode->next->next;
        for( int i = 0; i < length - 1; ++i ) {
            if( iter->val < midVal ) {
                preIter->next = iter->next;
                iter->next = preNode->next;
                preNode->next = iter;
 
                leftLength++;
                iter = preIter->next;
            }
            else {
                preIter = iter;
                iter = iter->next;
            }
        }
        quickSort(preNode, leftLength);
        quickSort(midIter, length - leftLength - 1);
    }
};

int main() {
	return 0;
}

