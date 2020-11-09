/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if      (l1==NULL && l2==NULL){return NULL;}
    else if (l1!=NULL && l2==NULL){return l1;}
    else if (l1==NULL && l2!=NULL){return l2;}   
    
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* res = malloc(sizeof(struct ListNode));
    struct ListNode* p = res;
    
    while(1){
        if((p1==NULL && p2!=NULL) || ((p1!=NULL && p2!=NULL) && (p2->val)<(p1->val))){
            p->val = p2->val;
            p2 = p2->next;
            //printf("(2:%d) ", p->val);
            if(p1==NULL && p2==NULL){
                p->next = NULL;
                break;
            }
            else{
                p->next = malloc(sizeof(struct ListNode));
                p = p->next;              
            }
        }
        else if((p1!=NULL && p2==NULL) || ((p1!=NULL && p2!=NULL) && (p1->val)<=(p2->val))){
            p->val = p1->val;
            //printf("(1:%d) ", p->val);
            p1 = p1->next; 
            if(p1==NULL && p2==NULL){
                p->next = NULL;
                break;
            }
            else{
                p->next = malloc(sizeof(struct ListNode));
                p = p->next;               
            }
        }
    }
    return res;
}