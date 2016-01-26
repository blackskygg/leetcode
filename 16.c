#include <stdlib.h>
#include <limits.h>

#define LEFT  0x01
#define RIGHT 0x02
#define BOTH  LEFT | RIGHT

int cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int threeSumClosest(int* nums, int numsSize, int target)
{
        int l, m, r, sum, closest, result;
        int mv_flag;

        qsort(nums, numsSize, sizeof(int), cmp);

        closest = INT_MAX;
        for(r = 2; r < numsSize; ++r) {
                while(r < numsSize - 1 && nums[r] == nums[r+1])
                        ++r;

                l = 0;
                m = r - 1;
                while(l < m) {
                        sum =  nums[l]+nums[m]+nums[r] - target;
                        if(abs(sum) < closest) {
                                closest = abs(sum);
                                result = sum + target;
                        }

                        if(0 == sum) {
                                return target;
                        } else if(sum > 0) {
                                mv_flag = LEFT;
                        } else {
                                mv_flag = RIGHT;
                        }

                        if(mv_flag & LEFT) {
                                m--;
                                while(m > l && nums[m] == nums[m + 1])
                                        m--;
                        }
                        if(mv_flag & RIGHT) {
                                l++;
                                while(l < m && nums[l] == nums[l - 1])
                                        l++;
                        }
                }
        }

        return result;
}
