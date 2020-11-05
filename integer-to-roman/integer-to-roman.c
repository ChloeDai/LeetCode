

char * intToRoman(int num){
    char* roman=calloc(sizeof(char), 16);
    uint8_t  index = 0;
    uint8_t  q = num/1000;
    uint16_t r = num%1000;
    
    for(uint8_t i=0;i<q;i++){
        roman[index] = 'M';
        index+=1;
    }
    
    q = r/100;
    r = r%100;
    
    if(q<4){
        for(uint8_t i=0;i<q;i++){
            roman[index] = 'C';
            index+=1;
        }
    }
    else if(q==9){
        roman[index] = 'C';
        roman[index+1] = 'M';
        index+=2;
    }
    else if(q>4){
        roman[index] = 'D';
        index+=1;        
        for(uint8_t i=0;i<(q-5);i++){
            roman[index] = 'C';
            index+=1;
        }
    }
    else{
        roman[index] = 'C';
        roman[index+1] = 'D';
        index+=2;
    }
    
    q = r/10;
    r = r%10;
    
    if(q<4){
        for(uint8_t i=0;i<q;i++){
            roman[index] = 'X';
            index+=1;
        }
    }
    else if(q==9){
        roman[index] = 'X';
        roman[index+1] = 'C';
        index+=2;
    }
    else if(q>4){
        roman[index] = 'L';
        index+=1;        
        for(uint8_t i=0;i<(q-5);i++){
            roman[index] = 'X';
            index+=1;
        }
    }
    else{
        roman[index] = 'X';
        roman[index+1] = 'L';
        index+=2;
    }
    
    if(r<4){
        for(uint8_t i=0;i<r;i++){
            roman[index] = 'I';
            index+=1;
        }
    }
    else if(r==9){
        roman[index] = 'I';
        roman[index+1] = 'X';
        index+=2;
    }
    else if(r>4){
        roman[index] = 'V';
        index+=1;        
        for(uint8_t i=0;i<(r-5);i++){
            roman[index] = 'I';
            index+=1;
        }
    }
    else{
        roman[index] = 'I';
        roman[index+1] = 'V';
        index+=2;
    }
    
    return roman;
    
}