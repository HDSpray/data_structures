#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// #include "lists.h"

typedef struct list_node list_node;

struct list_node {
    int data;   // value in Node
    list_node *next;  // link to the next node
};

struct stack {
    list_node *vals;   // link to the top node
};        

// create a new stack
stack_t create(void){
    struct stack *new;
    struct new = mallc(sizeof (struct stack);
    assert(new != NULL);
    new->vals = NULL;
    return new;
}

// add new item to stack
void push(stack_t stack){
    struct list_node *new;
    new = malloc(sizeof (struct list_node));
    new->data = item;
    new->next = stack->vals;
    stack->vals = new;
    
    /*
    stack->vals = insert(stack->valus, item)
    */
}

int pop(stack_t stack){
    int val = get_ith(stack->vals,0);
    stack->vals = delete_ith(stack->vals,0);
    return val;
}

// return ture if stack is empty    
int is_empty(stack_t stack){
    return (stack->vals == NULL);
}    

// free a stack
void destory(stack_t stack){
    free_list(stack->vals);
    free(stack);
}

// display contents of stack
void show(stack_t stack){
    printf("Stack: Top");
    show_list(stack->vals);
}


