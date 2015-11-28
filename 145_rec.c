/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void se_rec(struct TreeNode* curr, int *nodes, int *index)
{
        if(NULL != curr){
                se_rec(curr->left, nodes, index);
                se_rec(curr->right, nodes, index);

                nodes[*index] = curr->val;
                (*index)++;
        }

}

void count_rec(struct TreeNode *curr, int *count)
{
        if(NULL != curr){
                (*count)++;
                count_rec(curr->left, count);
                count_rec(curr->right, count);
        }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
        int index;
        int *nodes;

        *returnSize = 0;
        count_rec(root, returnSize);

        nodes = malloc(sizeof(int) * (*returnSize));
        index = 0;
        se_rec(root, nodes, &index);

        return nodes;
}
