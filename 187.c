#include <stdlib.h>
#include <stdboot.h>
#include <inttypes.h>
#include <string.h>

#define MAX 1048577

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int mark[MAX];
uint8_t map[128];
char** findRepeatedDnaSequences(char* s, int* returnSize) {
        char *curr = s;
        char **result = malloc(MAX * sizeof(char *));
        size_t pos = 0;
        int index;
        bool flag;

        *returnSize = 0;

        map['A'] = 0;
        map['T'] = 1;
        map['C'] = 2;
        map['G'] = 3;
        for(int i = 0; i < MAX; ++i)
                mark[i] = 0;

        for(;;) {
                flag = false;
                index = 0;
                for(int i = 0; i < 10; ++i) {
                        if('\0' == curr[i]) {
                                flag = true;
                                break;
                        } else {
                                index += map[curr[i]] * (1 << (i << 1));
                        }
                }

                if(flag)
                        break;

                if(1 == mark[index]) {
                        /* add to result list */
                        result[pos] = malloc(11);
                        memcpy(result[pos], curr, 10);
                        result[pos][10] = '\0';
                        pos++;
                }

                mark[index]++;
                curr++;
        }

        *returnSize = pos;

        return result;
}
