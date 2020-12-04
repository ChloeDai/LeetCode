int divide(int dividend, int divisor){
    int sign = ((dividend >= 0)^(divisor >= 0))?-1:1;                   //check the sign of the answer
    long long int dividend_long = dividend; //determind a long long int to handle the INT_MAX & INT_MIN cases
    dividend_long = dividend_long<0?dividend_long*(-1):dividend_long;   //abs(dividend_long)
    long long int divisor_long = divisor;   //determind a long long int to handle the INT_MAX & INT_MIN cases
    divisor_long = divisor_long<0?divisor_long*(-1):divisor_long;       //abs(divisor_long)
    long long int q = 0;
    
    for(int i=31;dividend_long>=divisor_long;i--){  //the 10/3 for example: binary(10)=1010, binary(3)=111
        long long int count = 0;                    //         0 0 1 1
        while(dividend_long >= (divisor_long<<i)){  //       __________
            count += 1;                             //   1 1 ) 1 0 1 0      1.1010-count(11<<2)<=0  count2 = 0
            dividend_long -= (divisor_long<<i);     //           1 1        2.1010-count(11<<1)<=0  count1 = 1
        }                                           //         ________     3. 100-count(11<<0)<=0  count0 = 1
        q += (count)<<i;                            //           1 0 0       
    }                                               //             1 1      q = ...+(count2<<2)+(count1<<1)+(count0<<0)
                                                    //         ________
    if((sign*q)>INT_MAX){                           //               1
        return INT_MAX;
    }
    else if((sign*q)<INT_MIN){
        return INT_MIN;
    }
    else{
        return (sign*q);
    }
}