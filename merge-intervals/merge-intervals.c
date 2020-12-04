/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int partition(int** sort, int size){
    int i = size-1;
    for(int j=0;j<size;j++){
        bool i_set = (i!=size-1);
        bool exchange = (sort[j][0]<=sort[size-1][0]);
        if(!i_set && !exchange){
            i=j;
        }
        else if(i_set && exchange){
            int* temp = sort[i];
            sort[i] = sort[j];
            sort[j] = temp;
            i++;
        }
    }
    
    return i;
}

void quicksort(int** sort, int size){
    if(size>>1){
        int new_size = partition(sort, size);
        quicksort(sort, new_size);
        quicksort(sort+new_size, size-new_size);
    }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    quicksort(intervals, intervalsSize);        //sort data before merge
    
    int index = 0;
    *returnSize = intervalsSize;
    
    for(int i=1;i<intervalsSize;i++){
        if(intervals[index][1] >= intervals[i][0]){     //if the respodent's min is smaller than the max of test data
            intervals[index][1] = intervals[index][1]>intervals[i][1]?intervals[index][1]:intervals[i][1];     //find bigger max value to merge
            *returnSize -= 1;
        }
        else{
            index += 1;                             //move the current index
            intervals[index] = intervals[i];        //and set new test data
        }
    }
    
    *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<(*returnSize);i++){
        (*returnColumnSizes)[i] = 2;
    }
    
    return intervals;
}