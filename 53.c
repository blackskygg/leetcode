#define max2(a,b) ((a)>(b)?(a):(b))

int maxn(int nums[], int numSize)
{
        int result = INT_MIN;

        for(int i = 0; i < numSize; ++i) {
                if(nums[i] > result)
                        result = nums[i];
        }

        return result;
}

int maxSubArray(int* nums, int numsSize) {
        int max[numsSize];

        max[0] = nums[0];
        for(int i = 1; i < numsSize; ++i)
                max[i] = max2(nums[i], nums[i] + max[i-1]);

        return maxn(max, numsSize);
}
