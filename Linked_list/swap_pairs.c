/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // recursion
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    
    struct ListNode* newHead = head->next;
    struct ListNode* next = head->next->next;
    head->next->next = head;
    head->next = swapPairs(next);
    
    return newHead;
}


// Fastest
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *node;
    struct ListNode **pp;
    
    node = head;
    pp = &head;
    while (node && node->next) {
        *pp = node->next;
        node->next = (*pp)->next;
        (*pp)->next = node;
        pp = &node->next;
        node = node->next;
    }
    return head;
}
