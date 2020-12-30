int climbStairs(int n){
    /*
        Stairs  |   Ways
          01    |    01
          02    |    02
          03    |    03      
          04    |    05     
          05    |    08
          06    |    13
        
        (the ways count of the target stair)
                          =
        (the ways count of the target stair-1)
                          +
        (the ways count of the target stair-2)
    */
    
    if(n<4){return n;}
    
    int stair0 = 2, stair1 = 3;
    for(;n>3;n--){
        int temp = stair0;
        stair0 = stair1;
        stair1 += temp;
    }
    return stair1;
}