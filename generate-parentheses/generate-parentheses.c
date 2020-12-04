void insert(char** res, int* returnSize, char* tmp, int n, int count, int left, int right){   
    if(!left && !right){
        res[*returnSize] = calloc(sizeof(char), 2*n+1);
        strcpy(res[*returnSize], tmp);
        *returnSize += 1;
        return;
    }
    
    if(left){
        tmp[n-count] = '(';
        insert(res, returnSize, tmp, n, count-1, left-1, right);
    }
    if(right && right>left){
        tmp[n-count] = ')';
        insert(res, returnSize, tmp, n, count-1, left, right-1);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** res = malloc(sizeof(char *) * 1430);
    char* tmp = calloc(sizeof(char), 2*n+1);
    *returnSize = 0;
    int left = n, right = n;
    
    insert(res, returnSize, tmp, n, n, left, right);
    return res;
}