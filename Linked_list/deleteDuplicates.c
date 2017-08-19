// Reverse a singly linked list.
/*
** For example,
** Given 1->1->2, return 1->2.
** Given 1->1->2->3->3, return 1->2->3.

** Definition for singly-linked list.
** struct ListNode {
**     int val;
**     struct ListNode *next;
** };
**/
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current = head;
    struct ListNode *n = NULL;
    
    if (head == NULL) {
        return NULL;
    }
    while (current) {
        n = current->next;
        while (n) {
            if (current->val != n->val) {
                break;
            }
            current->next = n->next;
            free(n);
            n = current->next;
        }
        current = current->next;
    }
    return (head);
    
}
