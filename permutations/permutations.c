/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void handler(int** res, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int* temp, int index){  
    if(index == numsSize){
        res[*returnSize] = malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        for(int i=0;i<numsSize;i++){
            res[*returnSize][i] = temp[i];
        }
        *returnSize += 1;
        return;
    }
    
    for(int i=0;i<numsSize;i++){
        while(nums[i]==20){     //check whether the num has been used or not.
            i += 1;
            if(i>=numsSize){return;}
        }
        temp[index] = nums[i];
        int temp_num = nums[i];
        nums[i] = 20;
        handler(res, nums, numsSize, returnSize, returnColumnSizes, temp, index+1); //set next index
        nums[i] = temp_num;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** res = malloc(sizeof(int*)*720);
    int* temp = malloc(sizeof(int)*numsSize);
    *returnColumnSizes = malloc(sizeof(int*)*720);
    *returnSize = 0;
    
    handler(res, nums, numsSize, returnSize, returnColumnSizes, temp, 0);
    
    return res;
}