void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int ptr1 = nums1Size-1;
    for(m=m-1,n=n-1;m>=0 && n>=0;){     //compare from the end of arrays
        nums1[ptr1--] = nums1[m]>=nums2[n]?nums1[m--]:nums2[n--];       //move the greater one to the end of nums1
    }
    for(;n>=0;n--){nums1[ptr1--] = nums2[n];}       //finish the remain elements in nums2
}