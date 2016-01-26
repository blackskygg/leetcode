#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[30], s2[30];
int cmp(const void *a, const void *b)
{
        int n1 = **(int *)a, n2 = **(int **)b;
        printf("%d, %d\n", n1, n2);
        sprintf(s1, "%d", n1);
        sprintf(s2, "%d", n2);
        return strcmp(s1, s2);
}
char* largestNumber(int* nums, int numsSize) {
        qsort(nums, numsSize, sizeof(int *), cmp);
        for(int i = 0; i < numsSize; ++i) {
                printf("%d\n", nums[i]);
        }

        return 0;
}

int main()
{
        int a[10] = {2, 56, 98, 55, 77, 12, 67, 90, 32, 10};
        largestNumber(a, 10);

        return 0;
}
