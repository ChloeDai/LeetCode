/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = NULL;
    struct ListNode* BP1 = NULL;
    struct ListNode* BP2 = NULL;    
    n -= m;
    
    //step 1 find m position
    if(m==1){       //if m==1, add a node before head
        BP1 = malloc(sizeof(struct ListNode));
        BP1->next = head;
        ptr1 = BP1;
    }
    else{           //find m position
        for(;m>2;m--){
            ptr1 = ptr1->next;
        }
        BP1 = ptr1;
    }
    ptr2 = ptr1 = ptr1->next;   //set ptr2 at ptr1->next
    BP2 = ptr1->next;           //set break point at the next potition of ptr1
    
    //step 2 revert & find n position
    for(;n && BP2;n--){         //reverse the direction of n nodes
        struct ListNode* temp = BP2->next;
        BP2->next = ptr2;
        ptr2 = BP2;
        BP2 = temp;
    }
    
    //step 3 ending
    ptr1->next = BP2;       //combine three lists
    BP1->next = ptr2;

    return m==1?ptr2:head;
}