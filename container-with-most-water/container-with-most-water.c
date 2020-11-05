int maxArea(int* height, int heightSize){
    int max_area = 0;
    int i = 0;
    int j = heightSize-1;
    
    while(i<j){
        int area = 0;
        if(height[i]<=height[j]){
            area = height[i]*(j-i);
            i+=1;
        }
        else{
            area = height[j]*(j-i);
            j-=1;
        }      
        if(max_area<area){max_area=area;}
    }
    
    return max_area;
}