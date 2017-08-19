/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* toBST(struct ListNode* head,struct ListNode* tail);
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    return toBST(head,NULL);
}

struct TreeNode* toBST(struct ListNode* head,struct ListNode* tail){
    if(head == tail){
        return NULL;
    }
    if(head->next == tail){
        struct TreeNode* new;
        new = malloc(sizeof(struct TreeNode));
        new->val = head->val;
        new->right = NULL;
        new->left = NULL;
        return new;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != tail && fast->next != tail){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode* root = NULL;
    root = malloc(sizeof(struct TreeNode));
    root->val = slow->val;
    root->right = NULL;
    root->left = NULL;
    root->right = toBST(slow->next,tail);
    root->left = toBST(head,slow);
    return root;
}
