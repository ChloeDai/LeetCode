void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int shift = 0;
    int temp = 0;
    int i = 0;
    while(matrixSize>1){
        int edge = shift+matrixSize-1;
        for(i=0;i<matrixSize-1;i++){
            temp = matrix[shift][shift+i];
            matrix[shift][shift+i] = matrix[edge-i][shift];
            matrix[edge-i][shift] = matrix[edge][edge-i];
            matrix[edge][edge-i] = matrix[shift+i][edge];
            matrix[shift+i][edge] = temp;
        }
        shift += 1;
        matrixSize -= 2;
    }

}