/** 
 * Given a list, rotate the list to the right by k places, where k is non-negative.

 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *ptr=head,*ptr1,*temp;
    int count=1,q=0;
    
    while(ptr!=NULL){
        q++;
        temp=ptr;
        ptr=ptr->next;
        
    }
    if(k>q && q!=0){
        k=k%q;
    }
    int l=q-k+1;
    ptr=head;
    ptr1=head;
    
    if(k==0 ||k==q){
        return head;
    }
    
    if(q==0 || q==1)return head;
    while(ptr!=NULL){
        if(count==(l))
            break;
        ptr1=ptr;
        ptr=ptr->next;
        count++;
    }
    ptr1->next=NULL;
    temp->next=head;
    head=ptr;
    return head;
}
