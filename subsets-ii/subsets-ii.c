/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void partition(int* nums, int size, int* size1, int* size2){
    int i = size;
    for(int j=0;j<size;j++){
        if(i==size && nums[j]>nums[size-1]){
            i=j;
        }
        else if(i!=size && nums[j]<=nums[size-1]){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    *size1 = i-1;
    *size2 = size-*size1-1;
}

void quick_sort(int* nums, int size){
    if(size<2){return;}
    int size1, size2;
    partition(nums, size, &size1, &size2);
    quick_sort(nums, size1);
    quick_sort(nums+size1+1, size2);
}

void setsubsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** res, int* temp, int index, int setsize, int next_ptr){
    if(index == setsize){
        res[*returnSize] = malloc(sizeof(int)*setsize);
        for(int i=0;i<setsize;i++){
            res[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = setsize;
        *returnSize += 1;
        return;
    }
    
    for(int ptr=next_ptr;ptr<numsSize;ptr++){
        temp[index] = nums[ptr];
        setsubsets(nums, numsSize, returnSize, returnColumnSizes, res, temp, index+1, setsize, ptr+1);
        while(ptr<numsSize-1 && nums[ptr] == nums[ptr+1]){      //skip the repeat elements;
            ptr++;
        }
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int max_len = 1<<numsSize;
    int** res = malloc(sizeof(int*)*max_len);
    int* temp = malloc(sizeof(int)*numsSize); 
    *returnColumnSizes = malloc(sizeof(int)*max_len);
    *returnSize = 0;
    
    quick_sort(nums, numsSize);     //sort te nums first
    for(int setsize=0;setsize<=numsSize;setsize++){     //the size of answer set from 0 to numsSize
        setsubsets(nums, numsSize, returnSize, returnColumnSizes, res, temp, 0, setsize, 0);
    }
    return res;
}