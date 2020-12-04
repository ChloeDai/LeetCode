int searchInsert(int* nums, int numsSize, int target){
    int start = -1, end = numsSize;
    
    while((end-start)>>1){
        int mid = (start+end)>>1;
        if(nums[mid] > target){
            end = mid;
        }
        else if(nums[mid] < target){
            start = mid;
        }
        else{
            start = end = mid;
            break;
        }
    }
    
    return end;
}