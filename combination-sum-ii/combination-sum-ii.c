/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combination(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int* tmp, int preindex, int candidatesindex){
    int index = preindex+1;
    if(!target){
        (*returnColumnSizes)[*returnSize] = index;
        res[*returnSize] = malloc(sizeof(int) * index);
        //printf("%d in %d : [ ", (*returnColumnSizes)[*returnSize], *returnSize);
        for(int i=0;i<index;i++){
            res[*returnSize][i] = tmp[i];
            //printf("%d ", res[*returnSize][i]);
        }//printf("]\n");
        *returnSize += 1;
        return;
    }
    else if(target>0){
        for(int i=candidatesindex;i<candidatesSize;i++){
            if(target-candidates[i] >= 0){
                //printf("%d %d %d\n", candidates[i], index, candidatesSize);
                tmp[index] = candidates[i];
                combination(candidates, candidatesSize, target-candidates[i], returnSize, returnColumnSizes, res, tmp, index, i+1);
            }
            while(i+1<candidatesSize && candidates[i] == candidates[i+1]){i+=1;}
        }
    }
}

void partition(int* sort, int size, int* size1, int* size2){
    int i = (-1);
    for(int j=0;j<size;j++){
        if(i==(-1) && sort[j]>sort[size-1]){
            i = j;
        }
        else if(i!=(-1) && sort[j]<=sort[size-1]){
            int temp = sort[j];
            sort[j] = sort[i];
            sort[i] = temp;
            i += 1;
        }
    }
    if(i==(-1)){i=size;}
    
    *size1 = i-1;
    *size2 = size-i;
}

void quicksort(int* sort, int size){
    if(size <= 1){
        return;
    }
    int size1=0, size2=0;
    partition(sort, size, &size1, &size2);
    quicksort(sort, size1);
    quicksort(sort+size1+1, size2);
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int** res = malloc(sizeof(int*) * 121);
    *returnColumnSizes = malloc(sizeof(int*)* 121);
    *returnSize = 0;
    int* tmp = malloc(sizeof(int) * 121);
    quicksort(candidates, candidatesSize);
    combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, tmp, -1, 0);
    free(tmp);
    return res;
}