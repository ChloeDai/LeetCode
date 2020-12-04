/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL){return head;}
    struct ListNode* a = head;
    struct ListNode* b = head->next;
    struct ListNode* c = head->next->next!=NULL?head->next->next:NULL;
    head = head->next;

    while(c != NULL && c->next != NULL){   
        a->next = c->next;
        b->next = a;
        
        a = c;
        b = b->next->next;
        c = c->next->next!=NULL?c->next->next:NULL;
    }
    a->next = c;
    b->next = a;
    
    return head;
}