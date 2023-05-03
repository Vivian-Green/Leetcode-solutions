int firstMissingPositive(int* nums, int numsSize){
    int numsMax = 1;
    int numsMaxIsBigger = 0;
    int numsIIsBigger = 0;
    int biggerOption = 0;
    int clampToNumsSize;

    for(int i=0; i < numsSize; i++){
        if(nums[i] < 1){
            continue;
        }
        numsMaxIsBigger = (numsMax > nums[i]) * numsMax;
        numsIIsBigger = (nums[i] >= numsMax) * nums[i];
        biggerOption = numsMaxIsBigger + numsIIsBigger;  

        if(numsSize+1 < biggerOption){
            numsMax = numsSize+1;
            continue;
        }
        numsMax = clampToNumsSize + biggerOption;
    }

    numsMax += 1;
    int* containedNums[numsMax];

    for(int i=0; i<numsSize; i++){
        if(nums[i] >= 1 && nums[i] < numsSize+1){
            containedNums[nums[i]] = 1;
        }
    }

    for(int i=1; i<numsMax; i++){
        if(containedNums[i] == 1){
            continue;
        }
        return i;
    }

    return numsMax;
}