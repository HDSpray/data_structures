/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) 
{
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    struct ListNode *res,*p;
    if(l1->val<l2->val){
        res=l1;
        l1=l1->next;
    }else{
        res=l2;
        l2=l2->next;
    }
    p=res;
    while(l1!=NULL&&l2!=NULL){
        if(l1->val<l2->val){
            p->next=l1;
            l1=l1->next;
        }else{
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    if(l1!=NULL){
        p->next=l1;
    }else{
        p->next=l2;
    }
    return res;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }else{
        struct ListNode *fast=head;
        struct ListNode *slow=head;
        while(fast->next != NULL  &&  fast->next->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow;
        slow=slow->next;
        fast->next=NULL;
        fast=insertionSortList(head);
        slow=insertionSortList(slow);
        return merge(fast,slow);
    }
    
}
