#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
        int* g[n];
        bool mark[n];
        int count[n], nremain;
        int *mhts = malloc(sizeof(int) * 2);
        size_t pos;

        //initialize the adjacent list
        for(int i = 0; i < n; ++i)
            count[i] = 0;

        for(int i = 0; i < edgesRowSize; ++i) {
                count[edges[i][1]]++;
                count[edges[i][0]]++;
        }

        for(int i = 0; i < n; ++i) {
                g[i] = malloc(sizeof(int) * (count[i]+1));
                g[i][0] = 0;
        }

        for(int i = 0; i < edgesRowSize; ++i) {
                g[edges[i][0]][++g[edges[i][0]][0]] = edges[i][1];
                g[edges[i][1]][++g[edges[i][1]][0]] = edges[i][0];
        }


        memset(mark, false, sizeof(mark));
        nremain = n;
        for(;;) {
                if(nremain <= 2)
                        break;

                for(int i = 0; i < n; ++i) {
                        if(mark[i])
                                continue;

                        //if it's a leaf, mark it out
                        if(count[i] == 1) {
                                mark[i] = true;
                                nremain--;
                        }
                }

                //update the degree of each node
                for(int i = 0; i < n; ++i) {
                        if(mark[i])
                                continue;

                        int t = 0;
                        for(int j = 1; j <= g[i][0]; ++j) {
                                if(!mark[g[i][j]])
                                        t++;
                        }

                        count[i] = t;
                }
        }

        pos = 0;
        for(int i = 0; i < n; ++i) {
                if(!mark[i])
                        mhts[pos++] = i;
        }

        *returnSize = nremain;
        return mhts;
}

