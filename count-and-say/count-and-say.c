char * countAndSay(int n){
    if(n==1){
        char* res = calloc(sizeof(char), (n+1));
        res[0] = '1';
        return res;
    }
    
    char* pre = countAndSay(n-1);
    char* res = calloc(sizeof(char), 4470);
    int index = 0;
    int count = 1;
    char check = pre[0];
    for(int i=1;i<strlen(pre)+1;i++){
        if(check == pre[i]){
            count += 1;
        }
        else{
            res[index] = count + '0';
            res[index+1] = check;
            check = pre[i];
            index += 2;
            count = 1;
        }
    }
    //free(pre);
    return res;
}