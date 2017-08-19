// bm.c ... Bracket matching

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void fail(char *);

int main(int argc, char *argv[]){

    int ch;            // current input char
    stack_t stack;     // stack of brackets
    
    stack = create();
    while((ch = getchar()) != EOF){
        if(ch == '(' || ch == '['  || ch == '{'){
            push(stack,ch);
        }else if(ch == ')'){
            if(is_empty(stack)) fail("(...)");
            if(pop(stack) != '(') fail("(...)");
        }else if(ch == ']'){
            if(is_empty(stack)) fail("[...]");
            if(pop(stack) != '[') fail("[...]");
        }else if(ch == '}'){
            if(is_empty(stack)) fail("{...}");
            if(pop(stack) != '{') fail("{...}");
        }
    }
    if(!is_empty(stack)) fail("close brackets");
    return EXIT_SUCCESS;
}            

void fail(char *c){
    printf("%s",c);
    printf("\n");
}
