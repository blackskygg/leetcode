#include <limits.h>

#define max2(a,b) ((a)>(b)?(a):(b))

int max(int nums[], int numSize)
{
        int result = INT_MIN;

        for(int i = 0; i < numSize; ++i) {
                if(nums[i] > result)
                        result = nums[i];
        }

        return result;
}

int update(int nums[], int numSize, int price, int n)
{
        int upper = (n+2 < numSize) ? n+1 : numSize - 1;
        int sign = (upper % 2 == 0) ? 1 : -1;

        //do it bottom-up
        for(int i = upper; i >= 1; --i) {
                nums[i] = max2(nums[i], nums[i-1] + sign * price);
                sign = -sign;
        }
}

int maxProfit(int k, int* prices, int pricesSize) {
        int nstatus = 2 * k + 1 > pricesSize + 1 ? pricesSize + 1 : 2 * k + 1;
        int *curr = malloc(sizeof(int) * nstatus);

        curr[0] = 0;
        for(int i = 1; i < nstatus; ++i)
                curr[i] = INT_MIN;

        for(int i = 0; i < pricesSize; ++i)
                update(curr, nstatus, prices[i], i);

        return max(curr, nstatus);
}
