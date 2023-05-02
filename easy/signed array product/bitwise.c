//-128 as an 8-bit signed int is 10000000
const int signBitMask = -128;

int signFunc(int x){
    int signBit = ((x & signBitMask) >> 7)*2+1;
    int isntZero = x != 0;
    return(isntZero*signBit);
}


int arraySign(int* nums, int numsSize){
    int sign = 1;
    for(int i = 0; i < numsSize; i++){
        sign *= signFunc(nums[i]);
    }

    return(sign);
}