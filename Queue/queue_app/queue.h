typedef struct queue *queue_t;

queue_t queue_create(void);               // create a new queue
void queue_free(queue_t queue);           // free a queue
void queue_enqueue(queue_t queue, int item); // add new item to queue
int queue_dequeue(queue_t queue);             // remove next item from queue and return it
int queue_is_empty(queue_t queue);        // return true if queue is empty
int queue_front(queue_t queue);             // return next item from queue but don't remove it
int queue_size(queue_t queue);            // return number elements in queue
