char* convert(char* s, int numRows) {
    if (numRows == 1) {return s;}
    
    int CycleNum = (2*numRows)-2, Num = 0;
    int Size = strlen(s);
    char *pS = malloc(1000);

    for (int i=0;i<numRows;i++) {
        for (int j=0;(i+j)<Size;j+=CycleNum) {
            *(pS+Num) = *(s+i+j);
            Num++;
            if (i!=0 && i!=numRows-1 && j+CycleNum-i<Size) {
                *(pS+Num) = *(s+j+CycleNum-i);
                Num++;
            }
        }
    }
    *(pS+Num) = '\0';
    return pS;
}