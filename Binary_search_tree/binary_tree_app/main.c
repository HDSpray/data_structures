#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

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
        }else if (cmd == '#'){
            printf("Length = %d\n",FindHeight(root));
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
        }else if (cmd == 't'){
            if(IsSort(root)){
                printf("Yes!\n");
            }else{
                printf("No\n");
            }
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
    printf("#   ... show heigh of tree\n");
    printf("s   ... show the data of the successor\n");
    printf("t   ... check whether tree is binary search tree\n");
    printf("p   ... show current tree inorder\n");
    printf("p   ... show current tree preorder\n");
    printf("p   ... show current tree postorder\n");
    printf("f   ... free current tree\n");
    printf("q   ... quit the program\n");
}
