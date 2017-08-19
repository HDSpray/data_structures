#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Data structure representation of Queue

#define MAX 2048

struct queue{
    int elements[MAX];  // contents of Queue
    int front;          // index to first element
    int back;           // index to last element
    int length;         // number of elemnets
};

// Implementation of operations on Queue
// All funtions assumenqueue parm is valid

// print a message and give up
static
void fatal(char *message){
    fprintf(stderr, "%s\n",message);
    exit(EXIT_FAILURE);
}

// create a new queue
queue_t queue_create(void){
    struct queue *new;
    new = malloc(sizeof(struct queue));
    if(new == NULL)fatal("Out of memory");
    new->front = new->back = new->length = 0;
    return new;
}    

// free a queue
void queue_free(queue_t queue){
    free(queue);
}   

// add new item to queue
void queue_enqueue(queue_t queue, int item){
    if(queue->length == MAX)fatal("Queue overflow");
    queue->back++;
    queue->length++;
    queue->elements[queue->back] = item;
}

// remove next item from queue and return it
int queue_dequeue(queue_t queue){
    int val;
    if(queue->length == 0)fatal("Queue underflow");
    val = queue->elements[queue->front];
    queue->front++;
    queue->length--;
    return val;    
}

// return ture if queue is empty
int queue_is_empty(queue_t queue){
    return(queue->length == 0); 
}

// return next item from queue but don't remove it
int queue_front(queue_t queue){
    if(queue->length == 0) fatal("Queue underflow");
    return queue->elements[queue->front];
}

// return number elements in queue

