struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* res = malloc(sizeof(struct ListNode));
    struct ListNode* ptr = res;
    uint8_t carry = 0;
    while(1){
        ptr->val = carry;      
        if(l1 != NULL){
            ptr->val += l1->val;
            l1 = l1->next;
        }
        
        if(l2 != NULL){
            ptr->val += l2->val;
            l2 = l2->next;
        }
   
        if(ptr->val >= 10){
            carry = 1;
            ptr->val %=10;
        }
        else{
            carry = 0;
        }
        
        if(l1!=NULL || l2!=NULL){
            ptr->next = malloc(sizeof(struct ListNode));
            ptr = ptr->next;
        }
        else{
            break;
        }
    }
    
    if(carry){
        ptr->next = malloc(sizeof(struct ListNode));
        ptr = ptr->next;
        ptr->val = carry;
    }
    ptr->next = NULL;

    return res;
}
