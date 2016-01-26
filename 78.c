#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(void *a, void *b)
{
        return *(int*)a - *(int*)b;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
        int len = 1 << numsSize;
        int **result;

        *returnSize = len;
        *columnSizes = malloc(len * sizeof(int));
        result = malloc(len * sizeof(int *));

        qsort(nums, numsSize, sizeof(int), cmp);
        for(int i = 0; i < len; ++i) {
                int nbit = 0;
                int pos = 0

                for(int j = 0; j < numsSize; ++j) {
                        if(i & (1 << j))
                                nbit++;
                }

                (*columnSizes)[i] = nbit;
                result[i] = malloc(nbit * sizeof(int));
                for(int j = 0; j < numsSize; ++j) {
                        if(i & (1 << j))
                                result[i][pos++] = nums[j];
                }
        }

        return result;

}
