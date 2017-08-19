// que.c .. manipulate queues

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void printHelp();

// main program reads/executes queue commands

int main(void){
    queue_t queue;       // the Queue
    char line[BUFSIZ];   // input line buffer
    char cmd;            // current command
    int val;             // value for current command
    int nargs;           // # args for command 
    int changed;         // did last cmd change queue?
    
    // creat empty queue
    queue = queue_create();
    
    // read/execut commands
    printf("Queues 1.0\n");
    printf(">");
    while(fgets(line,BUFSIZ,stdin) != NULL){
        changed = 0;
        nargs = sscanf(line,"%c %d", &cmd, &val);
        if(cmd == '+' && nargs == 2){
            queue_enqueue(queue,val);
            changed = 1;
        }else if(cmd == '-'){
            if(queue_is_empty(queue)){
                printf("Can't dequeue\n");
            }else{
                val = queue_dequeue(queue);
                printf("Served %d\n",val);
                changed = 1;
            }
        }else if (cmd == 't'){
        
        }else if(cmd == '?' && nargs ==2){
            if(search(val,list)){
                printf("Found\n");
            }else{
                printf("Not Found\n");
            }        
        }else if (cmd == '#'){
            printf("Length = %d\n",length(list));
        }else if (cmd == 's'){
            if(is_sorted(list)){
                printf("Sorted!\n");
            }else{
                printf("Not sorted\n");
            }            
        }else if (cmd == 'f'){
            free_list(list);
            list = NULL;
        }else if (cmd == 'p'){
            changed = 1;
        }else if (cmd == 'q'){
            break;
        }else {
            printf("Invalid command!\n");
            printHelp();
        }
        if(changed){
            printf("List");
            show_list(list);
        }
        printf(">");
    }   
    free_list(list);
    printf("\n");
    return EXIT_SUCCESS;
}



void printHelp(){

    printf("Pissible commands: \n");
    printf("i N ... insert N at start of list\n");
    printf("a N ... append N at end of list\n");
    printf("d N ... delete N from list\n");
    printf("? N ... check whether N in list\n");
    printf("#   ... show length of list\n");
    printf("s   ... check whether list is sorted\n");
    printf("p   ... show current list\n");
    printf("f   ... free current list\n");
    printf("q   ... quit the program\n");
}    
            
            


