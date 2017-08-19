/*
** Remove all elements from a linked list of integers that have value val.
** Example
** Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
** Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* curr;
    struct ListNode* tmp;
    struct ListNode new_head;
    new_head.next = head;
    curr = &new_head;
    while(curr->next){
        if(curr->next->val == val){
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        }else{
            curr = curr->next;
        }
    }
    return new_head.next;    
}
