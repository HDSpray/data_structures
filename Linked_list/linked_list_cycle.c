// Given a linked list, determine if it has a cycle in it
// special case  1->2->3->4->2   the tail on index 1 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
bool hasCycle(struct ListNode *head) {
  if (head) {
    for (struct ListNode *p = head, *q = head->next; q && q->next;
         p = p->next, q = q->next->next) {
      if (p == q) {
        return true;
      }
    }
  }
  return false;
}
