char * multiply(char * num1, char * num2){
    if(num1[0]=='0' || num2[0]=='0'){       //handle *0 cases
        char* res = calloc(sizeof(char), 2);
        res[0] = '0';
        return res;
    }
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    char* res = calloc(sizeof(char), num1_len + num2_len + 1);  //the max size will not exceed m+n
    
    for(int i=num2_len-1;i>=0;i--){
        for(int j=num1_len-1;j>=0;j--){
            int num = (num1[j]-'0') * (num2[i]-'0');    //num[j] * num2[i] will be store in res[i+j] & res[i+j+1]
            res[i+j+1] += num;
            res[i+j] += (res[i+j+1]/10);
            res[i+j+1] %= 10;
        }
    }
    
    for(int j=0;j<num1_len + num2_len;j++){     //int to char
        res[j] += '0';
    }

    return res+(res[0]=='0'?1:0);
}