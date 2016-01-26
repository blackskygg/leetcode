#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
        size_t len = strlen(s), off = 0;
        char *result = malloc(len + 1);
        int i, j, odd;

        if(1 == numRows) {
                strcpy(result, s);
                return result;
        }

        if(2 == numRows) {
                for(i = 0; i < len; i += 2)
                        result[off++] = s[i];
                for(i = 1; i < len; i += 2)
                        result[off++] = s[i];

                result[len] = 0;
                return result;
        }

        for(i = 1; i <= numRows; ++i) {
                if(1 == i || numRows == i) {
                        for(j = i - 1; j < len; j += 2 * (numRows -1))
                                result[off++] = s[j];
                } else {
                        j = i - 1;
                        odd = 1;
                        while(j < len) {
                                result[off++] = s[j];
                                j += odd ? 2 * (numRows - i) : 2 * (i - 1);
                                odd = !odd;
                        }
                }
        }

        result[len] = 0;
        return result;
}
