// time-complexity = O(n)
// space-complexity = O(1)-best
//                    O(n)-worst/avg

#include "tree.h"

void LevelOrder (Node *root)
{
	if(root == NULL) return;
	push(root);
	// while there is at least one discovered node
	while(!empty(q)){
		Node* curr = front(q);
		printf("%d ",curr->data);
		if(curr->left != NULL) push(q->left);
		if(curr->rigth != NULL) push(q->right);
		pop(); // removing the element at front
	}
}


