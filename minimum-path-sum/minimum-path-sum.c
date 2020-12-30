int minPathSum(int** grid, int gridSize, int* gridColSize){
    for(int i=1;i<gridColSize[0];i++){      //calculate the minimum path sum on top edge
        grid[0][i] += grid[0][i-1];
    }

    for(int i=1;i<gridSize;i++){            //calculate the minimum path sum on left edge
        grid[i][0] += grid[i-1][0];
    }
    
    for(int i=1;i<gridSize;i++){            //start from grid[1][1]
        for(int j=1;j<gridColSize[0];j++){
            grid[i][j] += (grid[i][j-1]<grid[i-1][j]?grid[i][j-1]:grid[i-1][j]);    //choose the smaller number to sum
        }
    }
    
    return grid[gridSize-1][gridColSize[0]-1];
}