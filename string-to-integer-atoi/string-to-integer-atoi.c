int myAtoi(char * s){
    int str_len = strlen(s);
    bool detect_nonspace = false;
    bool detect_number = false;
    bool negative = false;
    long res = 0;
    
    for(int i=0;i<str_len;i++){
        if(s[i]!=' '){
            if(s[i]=='-' && !detect_number){            //set negative if detect '-' when number is not detected
                if('0'>s[i+1] || '9'<s[i+1]){return 0;} //return 0 if next character is not a number
                negative = true;
            }
            else if(s[i]=='+' && !detect_number){       //set positive if detect '+' when number is not detected
                if('0'>s[i+1] || '9'<s[i+1]){return 0;} //return 0 if next character is not a number
                negative = false;
            }
            else if('0'<=s[i] && '9'>=s[i]){            //a number is detected
                detect_number = true;
                res = (res * 10) + (s[i]-'0');
                if(res>INT_MAX){break;}                 //check the overflow situation
            }
            else{
                break;
            }
            detect_nonspace = true;
        }
        else if(detect_nonspace){   //stop loop if 2nd nonspace appear after ''
            break;
        }
    }
    
    if(negative){
        res*=(-1);
        return res<INT_MIN?INT_MIN:res;
    }
    else{
        return res>INT_MAX?INT_MAX:res;
    }
}