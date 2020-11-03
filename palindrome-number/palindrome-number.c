bool isPalindrome(int x){
    if(x==0){return true;}
    if(x<0 || !(x%10)){return false;}
    
    int temp = x;
    long rev = 0;
    while(1){
        rev = (rev*10) + temp%10;
        if(rev>INT_MAX){return false;}
        temp /= 10;
        if(!temp){break;}
    }
    
    return (x==rev);
}