#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
        int *result = malloc(sizeof(int) * 2);
        int s, filter;

        *returnSize = 2;
        result[0] = result[1] = 0;
        s = 0;

        for(int i = 0; i < numsSize; ++i)
                s = s ^ nums[i];

        //the filter is used seperate the array into two catagories
        //each contains exactely one single number
        //because it's this bit that differs them
        filter = s & (-s);

        for(int i = 0; i < numsSize; ++i) {
                if(nums[i] & filter)
                        result[0] ^= nums[i];
                else
                        result[1] ^= nums[i];

        }

        return result;
}
