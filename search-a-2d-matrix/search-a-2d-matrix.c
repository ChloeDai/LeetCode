bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(!matrixSize || !(matrixColSize[0])){return false;}
    
    for(int i=0;i<matrixSize;i++){
        int len = matrixColSize[i]-1;
        if(target==matrix[i][0] || target==matrix[i][len]){
            return true;
        }
        else if(target<matrix[i][len]){
            for(int j=1;j<len;j++){
                if(target==matrix[i][j]){
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}