#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
};
void show(struct ListNode* head);
void free_list(struct ListNode* head);
struct ListNode* append(int val,struct ListNode* head);
struct ListNode* newlist(int val);
void reverseList_iterative(struct ListNode* head);
void add(struct ListNode* l1,struct ListNode* l2);
void touch(struct ListNode* head);
int main(void){
    struct ListNode* head = NULL;
    struct ListNode* list2 = NULL;
    list2 = append(1,list2);
    list2 = append(2,list2);
    list2 = append(3,list2);
    list2 = append(4,list2);
    list2 = append(5,list2);
    list2 = append(6,list2);
    
    head = append(1,head);
    head = append(2,head);
    head = append(3,head);
    head = append(4,head);
    head = append(5,head);
    head = append(6,head);
    show(head);
    add(head,list2);
    show(head);
    free(list2);
    free_list(head);
    return 0;
}

struct ListNode* newlist(int val){
    struct ListNode* new;
    new = malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode* append(int val, struct ListNode* head){
    if(head == NULL){
        head = newlist(val);
    }else if(head->next == NULL){
        head->next = newlist(val);
    }else{
        head->next = append(val,head->next);
    }
    return head;    
}

void show(struct ListNode* head){
    struct ListNode* curr;
    curr = head;
    while(curr){
        printf("%d ",curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void free_list(struct ListNode* head){
    struct ListNode* curr;
    curr = head;
    while(curr){
        curr = curr->next;
        free(head);
        head = curr;
    }
}

void touch(struct ListNode* head){
    head = NULL;
}
void add(struct ListNode* l1,struct ListNode* l2){
    while(l1 != NULL && l2 != NULL){
        l1->val = l2->val + l1->val;
        l1 = l1->next;
        l2 = l2->next;
    }
}
void reverseList_iterative(struct ListNode* head) {
    
    struct ListNode *current, *prev, *next;
    current = head;
        
    if(head == NULL) return;
    if(head->next == NULL) return;
    
    prev = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    head = prev;
}
