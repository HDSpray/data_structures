/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Reverse a singly linked list


// recursive method- head global
struct ListNode* head;

struct ListNode* reverseList(struct ListNode* p) {
    
    if(p == NULL) return p;
    
    if(p->next == NULL)
    {
        head =p;
        return head;
    }
    
    reverseList(p->next);
    
    struct ListNode* q = p->next;
    q->next = p;
    p->next = NULL;
    
    return head;
}

// iterative method- for first or head node , previous = NULL
struct ListNode* reverseList_iterative(struct ListNode* head) {
    
    struct ListNode *current, *prev, *next;
    current = head;
        
    if(head == NULL) return head;
    if(head->next == NULL) return head;
    
    prev = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    head = prev;
    return head;
}

