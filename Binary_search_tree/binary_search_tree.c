#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FOUND 1
#define NOT_FOUND 0

typedef struct BstNode BstNode_t;
struct BstNode{
    int data;
    BstNode_t *left;
    BstNode_t *right;
};
BstNode_t *GetNewNode(int data);
BstNode_t *Insert(BstNode_t *root,int data);
int Search(BstNode_t *root,int data);
BstNode_t *Delete(BstNode_t *root, int data);
void deleteTree(BstNode_t *node);
BstNode_t *FindMin(BstNode_t *root);
BstNode_t *GetSuccessor(BstNode_t *root,int data);
void Inorder(BstNode_t *root);
void Preorder(BstNode_t *root);
void Postorder(BstNode_t *root);
void printHelp();

int main(void)
{
    BstNode_t *root = NULL;  // Creating an empty tree
    char line[BUFSIZ];  // input line buffer
    char cmd;           // current command
    char option[BUFSIZ];        // option for current command
    int val;            // value for currrent command
    int nargs;          // # args for command
    int changed;        // did last cmd change list?
    
    // read/execute commands
    printf("Walcome to use the binary search tree!\n");
    printf("> ");
    while(fgets(line,BUFSIZ,stdin) != NULL ){
        changed = 0;
        nargs = sscanf(line,"%c %d", &cmd, &val);
        if(cmd == 'a' && nargs == 2){
            root = Insert(root,val);
            changed = 1;
        }else if (cmd == 'd' && nargs == 2){
            root = Delete(root,val);
            changed = 1;
        }else if(cmd == 's' && nargs == 2){
            BstNode_t *successor = GetSuccessor(root,val);
            printf("The successor of the %d is %d\n",val,successor->data);    
        }else if(cmd == '?' && nargs ==2){
            if(Search(root,val)){
                printf("Found\n");
            }else{
                printf("Not Found\n");
            }        
        //}else if (cmd == '#'){
        //    printf("Length = %d\n",length(list));
        }else if(cmd == 'a'){
            printf("Now is append mode\nPlease enter a value\n>");
            while(scanf("%d",&val) == 1){
                root = Insert(root,val);
                printf("Tree in order ");
                Inorder(root);
                printf("\n");
                printf("Please enter a value\n>");
            }    
        }else if (cmd == 'f'){
            deleteTree(root);
            printf("Tree deleted\n");
            root = NULL;
            changed = 1;
        }else if (cmd == 'p'){
            printf("Now is print mode\n");
            printf("Please enter the way you want to print\n");
            printf("The possible commands: \n");
            printf("\tinorder\n\tpreorder\n\tpostorder\n>");
            if(fgets(option,BUFSIZ,stdin) != NULL){
                if(strncmp("preorder",option,8) == 0){
                    Preorder(root);
                    printf("\n");
                }else if(strncmp("inorder",option,7) == 0){
                    changed = 1;
                }else if(strncmp("postorder",option,9) == 0){
                    Postorder(root);
                    printf("\n");
                }else{
                    continue;
                }    
            }else{
                continue;
            }
        }else if (cmd == 'q'){
            break;
        }else {
            printf("Invalid command!\n");
            printHelp();
        }
        if(changed){
            printf("Tree inorder ");
            Inorder(root);
            printf("\n");
        }
        printf(">");
    }   
    deleteTree(root);
    printf("Tree deleted\n");
    return EXIT_SUCCESS;
}    

void printHelp(){

    printf("Here is possible commands: \n");
    printf("a N ... append N of tree\n");
    printf("d N ... delete N from tree\n");
    printf("? N ... check whether N in tree\n");
    printf("#   ... show length of list\n");
    printf("s   ... show the data of the successor\n");
    printf("p   ... show current tree inorder\n");
    printf("p   ... show current tree preorder\n");
    printf("p   ... show current tree postorder\n");
    printf("f   ... free current tree\n");
    printf("q   ... quit the program\n");
}

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

BstNode_t *FindMin(BstNode_t *root)
{
    BstNode_t *curr_node = root;
    while(curr_node->left != NULL){
        curr_node = curr_node->left;
    }
    return curr_node;
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
