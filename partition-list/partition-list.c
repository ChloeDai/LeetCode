/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(!head){return head;}
    struct ListNode* res = NULL;
    struct ListNode* remain = NULL;
    struct ListNode* res_ptr = NULL;
    struct ListNode* remain_ptr = NULL;
    
    while(head){
        if(head->val < x){      //assign the node to the res list
            if(res_ptr){
                res_ptr->next = head;
                res_ptr = res_ptr->next;
            }
            else{
                res = head;
                res_ptr = res;
            }
        }
        else{
            if(remain_ptr){     //assign the node to the remain list
                remain_ptr->next = head;
                remain_ptr = remain_ptr->next;
            }
            else{
                remain = head;
                remain_ptr = remain;
            }
        }
        head = head->next;
    }
    
    if(!remain_ptr){            //if all of the node is greater than or equal to x
        res_ptr->next = remain;
        return res;
    }
    else if(!res){              //if all of the node is less to x
        remain_ptr->next = NULL;
        return remain;
    }
    remain_ptr->next = NULL;    //combine the res and remain list
    res_ptr->next = remain;
    return res;
}