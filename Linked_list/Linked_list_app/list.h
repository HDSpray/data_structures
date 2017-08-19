// lists.h .. linked list definitions
// linked list data types

struct node {
    int data;    // data value in Node
    struct node *next;  // pointer to following Node
};

// signatures for linked list funcitons

void show_list(struct node *l);
int length(struct node *l);
int search(int data,struct node *l);
int is_sorted(struct node *l);
struct node *insert(int data, struct node *l);
struct node *append(int data,struct node *l);
struct node *delete(int data, struct node *l);
void free_list(struct node *l);

