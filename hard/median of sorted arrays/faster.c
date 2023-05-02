const int Max32BitSignedInt = pow(2, 31)-1;


int getValToCompareAgainst(int index, int length, int* arrayFrom){
    if(index >= length){
        return Max32BitSignedInt;
    }
    return arrayFrom[index];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;
    int sorted[totalSize];
    int sortedProgress = 0;

    int compare1, compare2;

    int i1 = 0;
    for(int i2 = 0; sortedProgress  < totalSize;){
        //get lowest value from each array
        compare1 = getValToCompareAgainst(i1, nums1Size, nums1);
        compare2 = getValToCompareAgainst(i2, nums2Size, nums2);
        
        //add lower value to sorted[] WITHOUT branching

        sorted[sortedProgress] = (compare1 > compare2) * compare2 + (compare1 <= compare2) * compare1;
        i1 += (compare1 <= compare2);
        i2 += (compare1 > compare2);
        sortedProgress++;
    }

    float fTotalSize = (float) totalSize;
    if(totalSize % 2 == 0){
        float avg = (float) sorted[totalSize/2-1];
        avg += (float) sorted[totalSize/2];
        return(avg/2.0f);
    }else{
        return(sorted[(int) totalSize/2]);
    }
}