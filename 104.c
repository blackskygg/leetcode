#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
        int l, r;
        if(root == NULL)
                return 0;

        l = maxDepth(root->left);
        r = maxDepth(root->right);

        return l >= r ? l + 1 : r + 1;
}
