/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // Merge two sorted linked lists and return it as a new list. 
 // The new list should be made by splicing together the nodes of the first two lists.
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1&&!l2){
        return l1;
    }
    if(!l1&&l2){
        return l2;
    }
    if(!l1&&!l2){
        return NULL;
    }
    struct ListNode * head;
    struct ListNode * ret;
    if(l1->val > l2->val){
        head = l2;
        l2 = l2->next;
    }else{
        head = l1;
        l1 = l1->next;
    }
    ret = head;
    while(l1&&l2){
      if(l1->val>l2->val){
          head->next = l2;
          head = head->next;
          l2 = l2->next;
      } else{
           head->next = l1;
          head = head->next;
          l1 = l1->next;
      } 
        head->next = NULL;
    }
    if(l1)
        head->next = l1;
    if(l2)
        head->next = l2;
    return ret;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists_recursive(struct ListNode* l1, struct ListNode* l2) {
    
    if (l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } 
    
    else 
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    
}


