#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

BstNode_t *Delete(BstNode_t *root, int data){
    if(root == NULL){
        return root;
    }else if(data < root->data){
        root->left = Delete(root->left,data);
    }else if(data > root->data){
        root->right = Delete(root->right,data); 
    }else{  // Delete node
        if(root->left == NULL && root->right == NULL){
            printf("Deleting single node: %d\n",root->data);
            BstNode_t *tmp = root;
            root = NULL;
            free(tmp);
        }else if(root->left == NULL){
            BstNode_t *tmp = root;
            printf("Deleting single node: %d\n",tmp->data); 
            root = root->right;
            free(tmp);
        }else if(root->right == NULL){
            BstNode_t *tmp = root;
            printf("Deleting single node: %d\n",tmp->data);
            root = root->left;
            free(tmp);
        }else{
            BstNode_t *tmp = FindMin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right,tmp->data);
        }
    }
    return root;          
}

/*  This function traverses tree in post order to 
    to delete each and every node of the tree */
void deleteTree(BstNode_t *node) 
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
   
    /* then delete the node */
    printf("Deleting node: %d\n", node->data);
    free(node);
} 

