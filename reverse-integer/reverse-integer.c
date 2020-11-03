int reverse(int x){
    double res = 0;
    while(x){ 
        res = (res*10) + x%10;
        x /= 10;
    }
    return (res>INT_MAX||res<INT_MIN)?0:res;//you need to detect the overflow situation before it occured.
}