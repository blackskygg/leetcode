 /* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */

struct node{
        bool valid;
        int val;
};

struct bin_data{
        int num;
        struct node nodes[];
};


void se_rec(struct TreeNode* curr, struct node *nodes, int *index)
{
        if(NULL == curr){
                nodes[*index].valid = false;
                (*index)++;
        } else {
                nodes[*index].valid = true;
                nodes[*index].val = curr->val;
                (*index)++;

                se_rec(curr->left, nodes, index);
                se_rec(curr->right, nodes, index);
        }

}

void count_rec(struct TreeNode *curr, int *count)
{
        (*count)++;
        if(NULL != curr){
                count_rec(curr->left, count);
                count_rec(curr->right, count);
        }
}

char* serialize(struct TreeNode* root) {
        int count;
        struct bin_data *data;
        int index;

        count = 0;
        count_rec(root, &count);
        data = malloc(sizeof(struct bin_data) + count * sizeof(struct node));

        index = 0;
        se_rec(root, data->nodes, &index);

        return data;
}

struct TreeNode *de_rec(struct node *nodes, int *index)
{
        struct TreeNode *node;

        if(nodes[*index].valid == false){
                (*index)++;
                return NULL;
        }

        node = malloc(sizeof(struct TreeNode));
        node->val = nodes[*index].val;
        (*index)++;

        node->left = de_rec(nodes, index);
        node->right = de_rec(nodes, index);

        return node;
}
/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
        int index = 0;
        return de_rec(((struct bin_data*)data)->nodes, &index);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
