bool isValid(char * s){
    int len = strlen(s);
    if(len&1){return false;}
    
    char stack[len];
    int key = 0;
    
    for(int i=0;s[i];i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){  //push
            stack[key] = s[i];
            //printf("push %c\n", stack[key]);
            key++;
        }
        else{   //pop
            key -= 1;
            if( key < 0 ||
                ((s[i] == ')' && stack[key] != '(') ||
                 (s[i] == ']' && stack[key] != '[') ||
                 (s[i] == '}' && stack[key] != '{'))){
                return false;
            }
            //printf("pop %c\n", stack[key]);
        }
    }
    
    return key==0;
}