// linked list funcitons

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct list_node list_node;

struct list_node {
    int data;
    list_node *next;
};

list_node *append(int value, list_node *list);
int is_empty(list_node *list);
list_node *create_node(int val,list_node *ptr);
list_node *insert(int value, list_node *list);
list_node *first(list_node *list);
int length(list_node *list);
void print_list(list_node *list);
list_node *last(list_node *list);
int sum(list_node *list);
list_node *middle(list_node *list);
list_node *nth(int index, list_node *list);
int is_ascending(list_node *list);

int main(int argc, char *argv[]){

    list_node *list = NULL;
    list_node *node = NULL;
    int number;
    
    printf("Enter a number: ");
    while(scanf("%d",&number) == 1){
        list = append(number, list);
        printf("Enter a number: ");
    }
    if(is_empty(list)){
        printf("List is empty.\n");
        return 0;
    }
    printf("\nList entered was: ");
    print_list(list);
    node = first(list);
    printf("\nFirst element in list is: %d.\n",node->data);
    node = last(list);
    printf("Last element in list is: %d.\n",node->data);
    printf("Middle element in list is: %d.\n",middle(list)->data);
    printf("Length of list is: %d.\n",length(list));
    printf("Sum of the list is: %d.\n",sum(list));
    if(is_ascending(list)){
        printf("List is in ascending order.\n");
    }else{
        printf("List is not in ascending order.\n");
    }
    return 0;
}

int is_empty(list_node *list){
    if(list == NULL)
        return 1;
    else 
        return 0;
    // return (list == NULL);   if the list is empty it only sure return not zero.   
}

list_node *create_node(int val,list_node *ptr){               
    list_node *new;
    new = malloc(sizeof(list_node));
    if(new == NULL){
        fprintf(stderr,"out of memory\n");
        exit(EXIT_FAILURE);
    }    
    new->data = val;
    new->next = ptr;
    return new;
}                


// return pointer to first node in list
// NULL is returned if list is empty
list_node *insert(int value, list_node *list){
    list_node *new = create_node(value,list);
    return new;
}    

list_node *first(list_node *list){
    return list;
}

void print_list(list_node *list){
    list_node *curr;
    curr = list;
    printf("[");
    while(curr != NULL){
        // play with *curr
        printf("%d",curr->data);
        if(curr->next != NULL){
            printf(",");
        }
        curr = curr->next;
    }  
    printf("]");  
}

int length(list_node *list){
    list_node *curr;
    int counter =0;
    
    for(curr = list; curr != NULL; curr = curr->next){
        counter = counter +1;
    }    
    /*
    curr = list;
    while(curr != NULL){
        counter++;
        curr = curr->next;
    }
    */
    return counter;
}    

list_node *append(int value, list_node *list){
    list_node *curr;
    curr = list;
    // scan to last node
    while (curr != NULL){
        if(curr->next ==NULL) break;
        curr = curr->next;
    }
    if(curr == NULL){
        // curr == NULL 
        // list was originally empty
        return insert(value,list);
    }else {
        // curr != NULL && curr ->next ==NULL
        // list had ar least one list_node
        list_node *new = create_node(value,NULL);
        curr->next = new;
        return list;
    }        
}

list_node *last(list_node *list){
    if(list == NULL) return NULL;
    list_node *curr;
    curr = list;
    while(curr->next != NULL){
        curr = curr->next;
    }
    return curr;
}   

int sum(list_node *list){
    list_node *curr;
    curr = list;
    int sum1=0;
    while(curr != NULL){
        sum1 = sum1 + curr->data;
        curr = curr->next;
    }      
    return sum1;
}      

list_node *middle(list_node *list){
    if(list == NULL) return list;
    int mid = length(list)/2;
    return nth(mid,list);
}    

list_node *nth(int index, list_node *list){
    if(list ==NULL) return list;
    if(index > length(list)-1) return NULL;
    list_node *curr = list;
    for (int i=0;i<index;i++){
        curr = curr->next;
    }
    return curr;    
}    


int is_ascending(list_node *list){
    list_node *curr=list;
    if(list == NULL || list->next == NULL){        // if(length(list)<2)
        return 1;
    }
    while(curr -> next != NULL){
        if(curr->next->data < curr->data)
            return 0;
        curr = curr-> next;        
    }   
    return 1; 
}             
