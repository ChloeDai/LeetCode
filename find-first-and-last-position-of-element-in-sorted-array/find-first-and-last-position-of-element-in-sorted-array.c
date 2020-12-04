/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int half_search(int* nums, int size, int start, int target){
    if(size == 1){
        return nums[start] == target ? start : (-1);
    }
    int new_size = (size>>1)+(size&1);
    if(nums[start+new_size]==target){
        return start+new_size;
    }
    else if(nums[start+new_size]<target){
        return half_search(nums, new_size, start+(size>>1), target);
    }
    else{
        return half_search(nums, new_size, start, target);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int start = 0, end = 0, index = -1;
    
    if(!numsSize)   {index = (-1);}     //handle the empty array case
    else            {index = half_search(nums, numsSize, 0, target);}   //search the target
    
    if(index != (-1)){      //if the target is found
        int i=index;
        while(i>0 && nums[i-1] == nums[index])          {i -= 1;}   //search backward
        start = i;
        
        i=index;
        while(i<numsSize-1 && nums[i+1] == nums[index]) {i += 1;}   //search forward
        end = i;
    }
    else{                   //if the target is not found
        start = end = (-1);
    }

    int* res = malloc(sizeof(int)*2);
    res[0] = start;
    res[1] = end;
    *returnSize = 2;
    
    return res;
}