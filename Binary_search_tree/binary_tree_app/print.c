#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

void Inorder(BstNode_t *root)
{
    if(root == NULL){
        return;
    }else{
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }    
}

void Preorder(BstNode_t *root)
{
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(BstNode_t *root)
{
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);    
}


void LevelOrder(BstNode_t *root){
    if(root == NULL){
        return;
    }
        
}
