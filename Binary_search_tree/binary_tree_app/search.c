#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

int Search(BstNode_t *root,int data){
    if(root == NULL){
        return NOT_FOUND;
    }else if(root->data == data){
        return FOUND;
    }else if(root->data >= data){
        return Search(root->left,data);
    }else{
        return Search(root->right,data);
    }            
} 


BstNode_t *FindMin(BstNode_t *root)
{
    BstNode_t *curr_node = root;
    while(curr_node->left != NULL){
        curr_node = curr_node->left;
    }
    return curr_node;
}

BstNode_t *Find(BstNode_t *root,int data){
    if(root == NULL){
        return NULL;
    }
    if(data < root->data){
        return Find(root->left,data);
    }else if(data > root->data){
        return Find(root->right,data);
    }else{
        return root;
    }     
}

BstNode_t *GetSuccessor(BstNode_t *root,int data)
{
    // Search the Node
    BstNode_t *curr = Find(root,data);
    if(curr == NULL){
        return NULL;
    }
    // Case 1: Node has right subtree
    if(curr->right != NULL){
        return FindMin(curr->right);
    }
    // Case 2: No right subtree
    else {
        BstNode_t *successor = NULL;
        BstNode_t *ancestor = root;
        while(ancestor != curr){
            if(curr->data < ancestor->data){
                successor = ancestor;  
                // So far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }    
    return 0;
}
