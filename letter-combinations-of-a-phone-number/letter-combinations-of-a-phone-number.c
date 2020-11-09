char ** letterCombinations(char * digits, int* returnSize){
    if(!digits[0]){
        *returnSize = 0;
        return NULL;
    }
    
    const char symbol[8][5]={       //set map
        'a','b','c','\0','\0',
        'd','e','f','\0','\0',
        'g','h','i','\0','\0',
        'j','k','l','\0','\0',
        'm','n','o','\0','\0',
        'p','q','r','s','\0',
        't','u','v','\0','\0',
        'w','x','y','z','\0'
    };
    
    *returnSize = 1;
    for(int i=0;digits[i];i++){     //calculate total returnSize
        int index = digits[i] - '2';
        *returnSize *= strlen(symbol[index]);
    }
    int digits_len = strlen(digits)+1;
    char** res = malloc(sizeof(char*)*(*returnSize));       //allocate the array of pointer
    for(int i=0;i<(*returnSize);i++){                       //allocate the memory of string by each pointer
        res[i] = calloc(sizeof(char), digits_len);        
    }
    
    int index = digits[0] - '2';
    int q1 = (*returnSize);
    int q2 = q1/(strlen(symbol[index]));
    for(int i=0;digits[i];i++){
        for(int j=0;j<(*returnSize);j++){           //fill in the array in order 
            res[j][i] = symbol[index][(j%q1)/q2];   //insert each symbol by calculating with order : (j%q1)/q2
        }
        if(!digits[i+1]){break;}
        index = digits[i+1] - '2';
        q1 = q2;
        q2 = q1/(strlen(symbol[index]));
    }
    return res;
}