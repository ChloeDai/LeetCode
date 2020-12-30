int mySqrt(int x){//Newton's method
    if(x<2){return x;}
    int n1 = x>>1;
    int n2 = (n1+(x/n1))>>1;
    while(n1>n2){
        n1 = n2;
        n2 = (n1+(x/n1))>>1;
    }
    
    return n1;
}