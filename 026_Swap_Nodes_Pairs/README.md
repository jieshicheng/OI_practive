Question:
    Given a linked list, swap every two adjacent nodes and return its head
    Example:
       1->2->3->4 => 2->1->4->3

    Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed

Solution:
    head->1->2->3->4
    p1 is point to head, p2 is point to number of '1'.changed '1' and '2'
    
    code:
        p1->next = p2->next
        p2->next = p2->next->next
        p1->next->next = p2
        p1 = p2
        p2 = p2->next
