/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse (struct ListNode * L )
{
    struct ListNode * p = NULL ;
    struct ListNode * q = NULL ;
    struct ListNode * r = NULL ;
    
    if ( ( L == NULL) ||  ( L->next == NULL) )
        return L ;
    p = L ;
    q = p->next ;
    p->next = NULL ;
    while ( q != NULL )
    {
        r = q->next ;
        q->next = p ;
        p = q ;
        q = r ;             
    }  
    L = p ;
    return L ;
        
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sum = NULL  ;
    struct ListNode* sum_i = NULL ;
    int a1 = 0 ;
    int a2 = 0 ;
    int sum_all = 0 ;
    int carry = 0 ;
   
    
    
    l1 = reverse (l1) ;
    l2 = reverse (l2) ;
    /*
    sum = l1 ;
    while( sum != NULL)
    {
        printf( " %d\t", sum->val );
        sum = sum->next ;
    }
     sum = l2 ;
    while( sum != NULL)
    {
        printf( " %d\t", sum->val );
        sum = sum->next ;
    }
    */
    
   
    while( ( l1 != NULL ) || (l2 != NULL) || ( carry != 0 ))
    {
        sum_i = ( struct ListNode * ) malloc ( sizeof( struct ListNode )) ;
        if( l1 != NULL )
            a1 = l1->val ;
        else
            a1 = 0 ;
        if (l2 != NULL )
            a2 = l2->val ;
        else
            a2 = 0 ;
        sum_all = a1 + a2 + carry ;
        carry = sum_all / 10 ;
        sum_i->val = sum_all % 10 ;
        sum_i->next = NULL ;
        if( sum == NULL)
            sum = sum_i ;
        else
        {
            sum_i->next = sum ;
            sum = sum_i ;
        }
        if( l1 != NULL )
            l1 = l1->next ;
        else
            l1 = NULL ;
        if( l2 != NULL )
            l2 = l2->next ;
        else
            l2 = NULL ;
    }
    return sum ;
    
}
