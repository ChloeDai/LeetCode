/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int index = 0;
    int new_size = intervalsSize+1;
    int** new_ptr = realloc(intervals, sizeof(int*)*new_size);      //give one more space to intervals
    intervals = new_ptr;
    intervals[intervalsSize] = newInterval;         //insert to the last position
    
    for(index=0;index<intervalsSize;index++){       //find the right position and insert the newInterval
        if(newInterval[0] < intervals[index][0]){   //if the position is found
            for(int i=intervalsSize;i>index;i--){   //move the rest intervals back for 1 index
                intervals[i] = intervals[i-1];
            }
            intervals[index] = newInterval;         //insert the newInterval
            index++;
            break;
        }
    }   //if the whole loop is complete, the last position is the right place.
    
    *returnSize = new_size;
    index = (index-2)<0?0:(index-2);    //roll back 2 index (the previous loop add 1 more index after loop)
    for(int i=(index+1);i<new_size;i++){
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