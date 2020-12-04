int strStr(char * haystack, char * needle){
    int needle_len = strlen(needle);
    if(!needle_len){return 0;}
    
    for(int i=0;haystack[i];i++){
        if(!strncmp(haystack+i, needle, needle_len)){
            return i;
        }
    }
    return -1;
}