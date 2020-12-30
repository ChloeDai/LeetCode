/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void recursive(int* res, int n){
    if(n==0){
        res[0] = 0;
        return;
    }
    
    recursive(res, n-1);
    int half = 1<<(n-1);
    for(int i=half,j=half-1;j>=0;i++,j--){
        res[i] = res[j] | half;
    }
}

int* grayCode(int n, int* returnSize){
    *returnSize = (1<<n);
    int* res = malloc(sizeof(int)*(*returnSize));

    recursive(res, n);
    
    return res;
}