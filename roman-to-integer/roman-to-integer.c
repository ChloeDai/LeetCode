int romanToInt(char * s){
    uint16_t val = 0;
    uint16_t* map = malloc(sizeof(uint16_t)*89);
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    
    uint8_t index = 0;
    while(s[index]){
        if(s[index+1] && (map[s[index]])<map[s[index+1]]){  //check 4*(10^n) or 9*(10^n), 0<=n<=3
            //printf("%c %d\n", s[index], map[s[index]]);
            //printf("%c %d\n", s[index+1], map[s[index+1]]);
            val += (map[s[index+1]]-map[s[index]]);
            index += 2;
        }
        else{
            //printf("%c %d\n", s[index], map[s[index]]);
            val += map[s[index]];
            index += 1;
        }
    }
    
    free(map);
    return val;
}