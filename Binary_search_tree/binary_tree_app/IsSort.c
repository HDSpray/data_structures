#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
int IsLesser(BstNode_t *root,int data);
int IsGreater(BstNode_t *root,int data);
int IsSort(BstNode_t *root){
    if(root == NULL){
        return 1;
    }    
    if(IsLesser(root->left,root->data) 
        && IsGreater(root->right,root->data)
        && IsSort(root->left)
        && IsSort(root->right) ){
        return 1;
    }else{
        return 0;
    }    
}

int IsGreater(BstNode_t *root,int data){
    if(root == NULL){
        return 1;
    }
    if(root->data > data
        && IsGreater(root->left,data)
        && IsGreater(root->right,data)){
        return 1;
    }else{
        return 0;
    }    
}

int IsLesser(BstNode_t *root,int data){
    if(root == NULL){
        return 1;
    }
    if(root->data <= data
        && IsLesser(root->left,data)
        && IsLesser(root->right,data)){
        return 1;
    }else{
        return 0;
    }    
}
