char * convert(char * s, int numRows){
    if(numRows==1){return s;}

    char *substrings[numRows];      //determine numRows substrings 
    for(int i=0;i<numRows;i++){     //init substrings
        substrings[i] = malloc(sizeof(char)*80);
    }

    int i=0;
    int *str_len = calloc(sizeof(int), numRows);
    while(s[i]){
        for(int j=0;(j<numRows && s[i]);j++){   //insert each character downwards ↓
            substrings[j][str_len[j]] = s[i];
            str_len[j]++;            
            i++;
        }
        for(int j=numRows-2;(j>0 && s[i]);j--){ //insert each character upwards ↗
            substrings[j][str_len[j]] = s[i];
            str_len[j]++;
            i++;
        }
        //repeat till the end
    }

    int len = 0;
    for(int i=0;i<numRows;i++){ //combine substring to full string
        for(int j=0;j<str_len[i];j++){
            s[len] = substrings[i][j];
            len++;
        }
        free(substrings[i]);
    }
    free(str_len);
    return s;
}