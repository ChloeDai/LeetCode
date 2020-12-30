/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* ptr = head;
    struct ListNode* distinct = NULL;
    
    while(ptr && ptr->next){
        if(ptr->val == ptr->next->val){ //printf("find duplicate\n");
            int duplicate = ptr->val;
            ptr = ptr->next->next;      //this line is unnecessary. If this line is removed, the while loop on the next line will run two more turns.
            while(ptr && ptr->val == duplicate){
                ptr = ptr->next;
            }
            if(!distinct)   {head = ptr;}
            else            {distinct->next = ptr;}      
        }
        else{                           //printf("distinct\n");
            distinct = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}