/*
** Height of a node 
** the number of edges in longest path from the node to a leaf node
*/

/*
** Height of tree = height of root
** Height of tree with 1 node = 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

int FindHeight(BstNode_t *root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    if(leftHeight>rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }        
}

