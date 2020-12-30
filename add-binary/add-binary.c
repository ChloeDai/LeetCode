char * addBinary(char * a, char * b){
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = 1+(len_a>len_b?len_a:len_b);
    char* res = calloc(sizeof(char), len+1);
    int carry = 0;

    for(int i=0;i<len;i++){
        int a_num = len_a-i-1<0?0:a[len_a-i-1]-'0';
        int b_num = len_b-i-1<0?0:b[len_b-i-1]-'0';
        
        res[len-i-1] = ((carry+a_num+b_num)%2) + '0';
        carry = (carry+a_num+b_num)/2;
    }

    return res+(res[0]=='0'?1:0);
}