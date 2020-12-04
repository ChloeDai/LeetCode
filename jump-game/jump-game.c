bool canJump(int* nums, int numsSize){
    int target = numsSize-1;            //set target to end
    for(int i=numsSize-2;i>=0;i--){     //find good point
        if(i+nums[i]>=target){          //if good point is found
            target = i;                 //move target to current index
        }
    }
    return (target==0);                 //if move to index 0 in the end, return true
}