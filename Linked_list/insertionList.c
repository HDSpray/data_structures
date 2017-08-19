struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode *newhead = malloc(sizeof(struct ListNode));
    newhead->next = head;
    struct ListNode *cur = head->next, *pre = head, *p, *next;
    while(cur){
        next = cur->next;
        if(cur->val >= pre->val){
            pre = cur;
            cur = next;
        }
        else{
            p = newhead;
            pre->next = next;
            while(p->next->val < cur->val && p != pre){
                p = p->next;
            }
            struct ListNode *tmp = p->next;
            p->next = cur;
            cur->next = tmp;
            cur = next;
        }
    }
    return newhead->next;
}
