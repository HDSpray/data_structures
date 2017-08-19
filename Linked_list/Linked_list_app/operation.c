// lists.c .. linked list functions

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// make a new struct node with supplied value
// malloc new struct node and set its fields
// if malloc fails, print error and exit
// static == the funciton is private to this file

static struct node *make_node(int val){
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL ){
        fprintf(stderr,"Out of memory in newNode\n");
        exit(EXIT_FAILURE);
    }
    new->data = val;
    new->next = NULL;
    return new;
}

// display data values in a linked list
void show_list(struct node *L){
    if(L == NULL){
        printf("\n");
    }else{
        printf(" -> %d",L->data);
        show_list(L->next);
    }        
}

// count the number of nodes in a linked list
int length(struct node *L){
    if(L==NULL) 
        return 0;
    else
        return 1 + length(L->next); 
}        

int search(int val,struct node *L){
    struct node *curr;
    curr =L;
    while(curr != NULL){
        // process curr node
        if(curr->data == val) return 1;
        curr = curr->next;
    }    
    return 0;
}  
                    
// insert a new value at the start of a linked list
struct node * insert(int val,struct node*L){
    struct node *new;
    new = make_node(val);
    new->next = L;
    return new;
}

// insert a new value at the end of a linked list
struct node *append(int val,struct node *L){
    if(L==NULL){
        return insert(val,L);
    }else if(L->next == NULL){
        L->next = insert(val,NULL);
        return L;
    }else{
        L->next = append(val,L->next);
        return L;
    }        
}


// remove a value from a linked list
// if value is not in the lisk, list unchangeed
// if value occures multiple times, remove first occurrence
struct node *delete(int val,struct node *L){
    struct node *curr = L, *prev = NULL;
    while(curr != NULL){
        if(curr->data == val) break;
        prev = curr;
        curr = curr->next;    
    }
    if (curr == NULL){   // val not in list
        return L;
    }else if (prev == NULL){  // delete first node
        L = curr->next;
        free(curr);
        return L;
    }else {                    // delete node in "middle" of the list
        prev->next = curr->next;
        free(curr);
        return L;
    }                
}

// remove all the nodes in linked list
void free_list(struct node *L){
    if(L==NULL){
        return;
    }else{
        free_list(L->next);
        printf("Deleting node %d\n",L->data);
        free(L);
    }
}            

// check whether list sorted in ascending order
int is_sorted(struct node *L){
    if(L == NULL){
        return 1;
    }else if(L->next ==NULL){
        return 1;
    }else if(L->data > L->next->data){
        return 0;
    }else{
        return is_sorted(L->next);
    }
}                
               
