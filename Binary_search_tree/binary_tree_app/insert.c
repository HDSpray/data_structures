#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

BstNode_t *GetNewNode(int data){
    BstNode_t *newNode = malloc(sizeof(struct BstNode));
    assert(newNode != NULL);
    newNode->data = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode_t *Insert(BstNode_t *root,int data){
    if(root == NULL){ // empty tree
        root = GetNewNode(data);
        return root;
    }else if(data <= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;    
}  
