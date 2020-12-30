int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[0][0]){return 0;}
    int i;
    for(i=0;i<obstacleGridSize && !obstacleGrid[i][0];i++){
        obstacleGrid[i][0] = 1;
    }
    for(;i<obstacleGridSize;i++){
        obstacleGrid[i][0] = 0;
    }
    
    for(i=1;i<obstacleGridColSize[0] && !obstacleGrid[0][i];i++){
        obstacleGrid[0][i] = 1;
    }
    for(;i<obstacleGridColSize[0];i++){
        obstacleGrid[0][i] = 0;
    }
    
    for(i=1;i<obstacleGridSize;i++){
        for(int j=1;j<obstacleGridColSize[i];j++){
            if(!obstacleGrid[i][j]){obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];}
            else{obstacleGrid[i][j] = 0;}
        }
    }
    
    return obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1];
}