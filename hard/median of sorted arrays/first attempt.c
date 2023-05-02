const int Max32BitSignedInt = 2147483647;


int getValToCompareAgainst(int index, int length, int* arrayFrom){
    //printf("len: %d, accessing: %d\n", length, index);
    if(index >= length){
        return Max32BitSignedInt;
    }else{
        //printf("value: %d\n", arrayFrom[index]);
        return arrayFrom[index];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;
    int sorted[totalSize];
    int sortedProgress = 0;
    int i1 = 0;
    int i2 = 0;

    int32_t compare1, compare2;

    for(int j = 0; j < totalSize; j++){
        compare1 = getValToCompareAgainst(i1, nums1Size, nums1);
        compare2 = getValToCompareAgainst(i2, nums2Size, nums2);
        
        
        //printf("num %d / %d, numbers: %d, %d \n", j+1, totalSize, compare1, compare2);
        if(compare1 > compare2){
            //printf("2nd is lower - %d\n", compare2);
            sorted[sortedProgress] = compare2;
            i2++;
            sortedProgress++;
        }else{
            //printf("1st is lower - %d\n", compare1);
            sorted[sortedProgress] = compare1;
            i1++;
            sortedProgress++;
        }
    }

    float fTotalSize = (float) totalSize;
    if(totalSize % 2 == 0){
        float medianFirst = (float) sorted[(int) floor(fTotalSize/2)-1];
        float medianSecond = (float) sorted[(int) floor(fTotalSize/2)];
        return((medianFirst+medianSecond)/2.0f);
    }else{
        return(sorted[(int) floor(fTotalSize/2.0f)]);
    }

    return 1.0;
}