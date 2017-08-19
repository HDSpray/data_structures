/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumber(struct ListNode* l1,struct ListNode* l2){
	struct ListNode* head = malloc(sizeof(struct ListNode));
	struct ListNode* output = head;
	output->next = NULL;

	int num = 0;
	int overNow = 0;
	int overNext = 0;
	int mode = 0;
	
	while(mode < 4){
		if(mode == 0){
			num = l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
		}else if(mode == 1){
			num = l2->val;
			l2 = l2->next;
		}else if(mode == 2){
			num = l1->val;
			l1 = l1->next;
		}

		num = overNow + num;
		if( num > 9){
			num = num - 10;
			overNext = 1;
		}
		
		output->val = num;
		overNow = overNext;
		overNext = 0;
		
		if( l1 == NULL && l2 != NULL){
			mode = 1;
		}
		if( l1 != NULL && l2 == NULL){
			mode = 2;
		}
		if( l1 == NULL && l2 == NULL && overNow != 0){
			mode = 3;
			num = 0;
		}
		if( l1 == NULL && l2 != NULL && overNow == 0){
			mode = 4;
		}
		if(mode < 4){
			output->next = malloc(sizeof(struct ListNOde);
			output->next->next = NULL;
			output = output->next;
		}
	}
	return head;
}
	}
}
