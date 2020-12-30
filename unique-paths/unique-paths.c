int uniquePaths(int m, int n){
    int map[n][m];          //Init map
    for(int i=0;i<n;i++){   //  1 1 1 1 ...
        map[i][0] = 1;      //  1 ? ? ? ...
    }                       //  1 ? ? ? ...
    for(int i=0;i<m;i++){   //  1 ? ? ? ...
        map[0][i] = 1;      // ...
    }
    
    for(int i=1;i<n;i++){   //counting
        for(int j=1;j<m;j++){
            map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
    return map[n-1][m-1];
}


/* The code below works, but time limit exceeded
void move(int m, int n, int steps, int* path_count){
    if(m+n == 2){
        *path_count += 1;
        return;
    }
    if(m!=1)    {move(m-1, n, 0, path_count);}
    if(n!=1)    {move(m, n-1, 0, path_count);}
}

int uniquePaths(int m, int n){
    int path_count = 0;
    move(m, n, 0, &path_count);
    return path_count;
}
*/
