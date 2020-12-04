int removeElement(int* nums, int numsSize, int val){
    if(!numsSize){return 0;}
    int index = 0;
    
    for(int i=0;i<numsSize;i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index += 1;
        }
    }

    return index;
}