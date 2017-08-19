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
int FindHeight(BstNode_t *root);
int IsSort(BstNode_t *root);
