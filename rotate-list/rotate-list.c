/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head){return head;}
    
    struct ListNode* ptr = head;
    struct ListNode* tail = head;
    struct ListNode* end = NULL;
    
    for(int i=0;i<k;i++){       //keep moving right for k step
        if(!ptr->next){             //if reach to the end of list before finishing moving:
            k%=(i+1);                   //do k = k % (length of list) to make k smaller than length of list(i+1)
            i=(-1);                     //set i to -1 then the loop will add 1 to make i to 0
            end = ptr;                  //indicate the end of list
            ptr->next = head;           //make the list to a ring
        }
        ptr = ptr->next;            //move to next node
    }
        
    while(ptr != end){          //keep moving till the end
        if(!ptr->next){             //if reach to the end of list after moving right:
            ptr->next = head;           //make the list to a ring
            head = tail->next;          //the next node of tail will be the new head of the new list
            tail->next = NULL;          //break the ring at the position of tail
            return head;                //return new head
        }
        ptr = ptr->next;            //move to next node
        tail = tail->next;          //move to next node
    }
    
    head = tail->next;          //the next node of tail will be the new head of the new list after ptr reach to the end
    tail->next = NULL;          //break the ring at the position of tail
    return head;                //return new head
}