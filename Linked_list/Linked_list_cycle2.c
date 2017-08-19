/** 
  * Definition for signly-linked list
  * struct ListNode{
  * 	int val;
  * 	struct ListNode *next;
  * };
  */
  
/*
 * L1 is defined as the distance between the head point and entry point
 * L2 is defined as the distance between the entry point and the meeting point
 * C is defined as the length of the cycle
 * n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer
According to the definition of L1, L2 and C, we can obtain:

 * the total distance of the slow pointer traveled when encounter is L1 + L2

 * the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C

Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:

2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*

It can be concluded that the distance between the head location and entry location is equal to the distance between the meeting location and the entry location along the direction of forward movement.

*/

struct ListNode *detectCycle(struct ListNode *head){
	if(head == NULL){
		return NULL;
	}
	struct ListNode *slow = head, *fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	if(fast == NULL || fast == =NULL){
		return NULL;
	}
	slow = head;
	while(slow !=fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
