/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void setIp(char* s, int* returnSize, char** res, char* temp, int size, int index, int temp_index, int dot){
    if(temp_index == size){
        res[*returnSize] = calloc(sizeof(char), size);
        for(int i=0;temp[i];i++){
            res[*returnSize][i] = temp[i];
        }
        *returnSize += 1;
        return;
    }
    
    char div = dot==3?0:'.';
    
    if(dot<4 && s[index]){     //there are only 3 dots in an IP address.
        temp[temp_index] = s[index];
        temp[temp_index+1] = div;
        setIp(s, returnSize, res, temp, size, index+1, temp_index+2, dot+1);
    }
    else{return;}
    
    if(s[index+1] && s[index]>'0') {    //2 digits value should greater than 09
        temp[temp_index+1] = s[index+1];
        temp[temp_index+2] = div;
        setIp(s, returnSize, res, temp, size, index+2, temp_index+3, dot+1);
    }
    else{return;}
    int val = (100*(s[index] - '0'))+(10*(s[index+1] - '0'))+(s[index+2] - '0');
    if(s[index+2] && val < 256){        //3 digits value should less than 256
        temp[temp_index+2] = s[index+2];
        temp[temp_index+3] = div;
        setIp(s, returnSize, res, temp, size, index+3, temp_index+4, dot+1);
    }
    else{return;}
}

char ** restoreIpAddresses(char * s, int* returnSize){
    *returnSize = 0;
    int len = strlen(s)+4;
    if(len < 8 && len > 16){return NULL;}
    
    char** res = malloc(sizeof(char*)*19);
    char* temp = calloc(sizeof(char), len);
    
    setIp(s, returnSize, res, temp, len, 0, 0, 0);
    
    return res;
}