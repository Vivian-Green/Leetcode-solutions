/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //set returnSize value even though this not being set wasn't mentioned in the description and would obviously be 2
    //it's the "twoSum" function like what else do you expect this to return
    *returnSize = 2;
    //init & malloc array[2] to be returned
    int *indicesArray = malloc(*returnSize * sizeof(int));


    //nested loop to try every combination, except those that've been tried already.
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                indicesArray[0] = i;
                indicesArray[1] = j;
                return indicesArray;
            }
        }
    }
    //necessary even though the code will never make it here with valid inputs.
    return NULL;
}

//"Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?"

/*technically this is just under half of O(n^2) in the worst case (correct solution is [#nums-1, #nums])
I believe the actual worse case would be O(0.5(n^2)-n-1) which is... a lot.
Luckily nobody really cares, and the largest term here is n^2 so this is.. O(n^2) enough. It *is* still quadratic


diagram of checked numbers in worse case:
    i value:
     0  1  2  3  4
j  0[ ][ ][ ][ ][ ]           key:
v  1[c][ ][ ][ ][ ]             checked = [c]
a  2[c][c][ ][ ][ ]             found = [x]
l  3[c][c][c][ ][ ]             unchecked = [ ]
u  4[c][c][c][x][ ]
e

*/