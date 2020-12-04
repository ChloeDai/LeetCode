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
        
        while(i+1<numsSize && nums[i+1]==nums[i]){      //skip if next num is same as current num
            i += 1;
        }
    }
}

void partition(int* sort, int size, int* size1, int* size2){
    int i = size;
    for(int j=0;j<size;j++){
        if(i==size && sort[j]>sort[size-1]){
            i=j;
        }
        else if(i!=size && sort[j]<=sort[size-1]){
            int temp = sort[i];
            sort[i] = sort[j];
            sort[j] = temp;
            i+=1;
        }
    }
    
    *size1 = i-1;
    *size2 = size-i;
}

void quicksort(int* sort, int size){
    if(size<=1){return;}
    int size1=0, size2=0;
    partition(sort, size, &size1, &size2);
    quicksort(sort, size1);
    quicksort(sort+size1+1, size2);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** res = malloc(sizeof(int*)*630);
    int* temp = malloc(sizeof(int)*numsSize);
    *returnColumnSizes = malloc(sizeof(int*)*630);
    *returnSize = 0;
    
    quicksort(nums, numsSize);
    handler(res, nums, numsSize, returnSize, returnColumnSizes, temp, 0);
    
    return res;
}

