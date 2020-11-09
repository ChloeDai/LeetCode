/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next == NULL){     //if there is only one node
        //free(head);
        return NULL;
    }
    
    struct ListNode* ptr = head;
    for(int i=n;i>0;i--){       //move to offset n
        ptr = ptr->next;
    }
    
    if(ptr==NULL){              //if ptr==NULL after move to offset, that means the first node needs to be removed.
        //ptr = head;
        head = head->next;
        //free(ptr);
        return head;
    }

    struct ListNode* ptr_n = head->next;
    struct ListNode* ptr_n_1 = head;
    
    while(ptr->next != NULL){   //move together till the end.
        ptr = ptr->next;
        ptr_n = ptr_n->next;
        ptr_n_1 = ptr_n_1->next;
    }
    
    ptr_n_1->next = ptr_n->next;    //remove
    //free(ptr_n);
    return head;
    
}