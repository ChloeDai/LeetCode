/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* res = malloc(sizeof(int)*(digitsSize+1));
    int carry = 0;
    digits[digitsSize-1] += 1;
    for(int i=digitsSize;i>0;i--){
        res[i] = (carry+digits[i-1])%10;
        carry = (carry+digits[i-1])/10;
    }
    res[0] = carry;
    *returnSize = digitsSize+carry;
    return res+(!carry);
}