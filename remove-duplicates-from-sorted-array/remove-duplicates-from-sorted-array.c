int removeDuplicates(int* nums, int numsSize){
    if(!numsSize){return 0;}
    int index = 0;
    
    for(int i=1;i<numsSize;i++){
        if(nums[index] != nums[i]){
            index += 1;
            nums[index] = nums[i];
        }
    }

    return index+1;
}