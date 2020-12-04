

void partition(int* sort, int size, int* size1, int* size2){
    int i=-1;
    for(int j=0;j<size;j++){
        if(i==(-1) && sort[j]>sort[size-1]){
            i=j;
        }
        else if(i!=(-1) && sort[j]<=sort[size-1]){
            int temp = sort[i];
            sort[i] = sort[j];
            sort[j] = temp;
            i+=1;
        }
    }
    
    if(i==(-1)){
        i=size-1;
    }
    
    *size1 = i;
    *size2 = size-i;
}

void quicksort(int* sort, int size){
    if(size == 1){return;}
    int size1, size2;
    partition(sort, size, &size1, &size2);
    quicksort(sort, size1);
    quicksort((sort+size1), size2);
}

void nextPermutation(int* nums, int numsSize){
    if(numsSize == 1){return;}
    
    for(int i=numsSize-2;i>=0;i--){     //start from last 2 elements
        int next = 101;
        int index = 0;
        int sort[numsSize-i-1];
        sort[0] = nums[i];
        for(int j=i+1;j<numsSize;j++){  //find the value which just large than num[i]
            if(nums[j]>nums[i] && next>nums[j]){
                if(next != 101){
                    sort[index] = next;
                }
                next = nums[j];
            }
            else{
                sort[index] = nums[j];
            }
            index += 1;
        }
        if(next != 101){
            quicksort(sort, numsSize-i-1);  //sort the rest elements
            nums[i] = next;
            for(int k=0;k<numsSize-i-1;k++){
                nums[i+1+k] = sort[k];
            }
            return;
        }
    }
    quicksort(nums, numsSize);  //sort all if nums has no next permutation
}