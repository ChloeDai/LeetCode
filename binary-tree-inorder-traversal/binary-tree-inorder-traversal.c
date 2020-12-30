/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void trace(struct TreeNode* node, int* returnSize, int* res){
    if(!node){return;}
    trace(node->left, returnSize, res);     //trace left first
    res[*returnSize] = node->val;           //after tracing left, set the value of itself
    *returnSize += 1;    
    trace(node->right, returnSize, res);    //then trace right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* res = malloc(sizeof(int)*100);
    trace(root, returnSize, res);
    return res;
}