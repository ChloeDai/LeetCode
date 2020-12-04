/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int ** res = malloc(sizeof(int*)*n);
    *returnColumnSizes = malloc(sizeof(int)*n);
    *returnSize = n;
    for(int i=0;i<n;i++){
        res[i]= malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    
    int shift = 0;
    int index = 1;
    int size = n*n;

    while(index < size){
        for(int i=shift;i<n-1-shift && (index <= size);i++,index++){
            res[shift][i] = index;//printf("%d ", res[shift][i]);
        }

        for(int i=shift;i<n-1-shift && (index <= size);i++,index++){
            res[i][n-1-shift] = index;//printf("%d ", res[i][n-1-shift]);
        }

        for(int i=n-1-shift;i>shift && (index <= size);i--,index++){
            res[n-1-shift][i] = index;//printf("%d ", res[n-1-shift][i]);
        }

        for(int i=n-1-shift;i>shift && (index <= size);i--,index++){
            res[i][shift] = index;//printf("%d ", res[i][shift]);
        }
        shift += 1;
    }
    
    if(index == size){
        res[n>>1][n>>1] = index;
    }
    
    return res;
}