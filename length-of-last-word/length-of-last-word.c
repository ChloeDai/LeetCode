int lengthOfLastWord(char * s){
    int len = strlen(s);
    int i = len-1;
    for(;i>=0 && s[i]==' ';i--,len--){} //discard the ' ' from the end of string
    for(;i>=0 && s[i]!=' ';i--){}       //count the letters until meet ' '
    return len-i-1;
}