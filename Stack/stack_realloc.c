#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define INITIAL_SIZE 64

struct stack{
    int *element;   // pointer to array of items 
    int size;       // current size of array
    int top;        // index of next elem to use
};                  // also funcitons as counter

// create a new stack
stack_t create(void){
    struct stack new;
    new = malloc (sizeof (struct stack));
    new->size = INITIAL_SIZE;
    new->top = 0;
    new->elements = malloc(INITIAL_SIZE*sizeof(int));
    assert(new->elements != NULL);
    return new;
}
// add new item to stack
void push(stack_t stack, int item){
    assert(stack != NULL);
    if(stack->top == stack->size){
        stack->size = stack->size *2;
        stack->elements = realloc(stack->elements, stack->size*sizeof(int));
    }    
    stack->elements[stack->top]=item;
    stack->top++;
}

// remove top item from stack and return it
int pop(stack_t stack){
    int val;  // return value
    
    assert(stack != NULL);
    if(stack->top == 0){
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    val = stack->elements[stack->top-1];
    stack->top--;
    return val;    
}

// 
void show(stack_t stack){
    printf("Stack: ");
    for(int i = 0; i < stack->top; i++){
        printf(" %d", stack->elements[i]);
        if(i < stack->top-1)printf(",");
    }
    printf(" Top\n");    
}

// free stack
void destroy(stack_t stack){
    free(stack->elements);
    free(stack);
}
