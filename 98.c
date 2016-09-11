#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;;
 *     struct TreeNode *right;
 * };
 */

int prev = INT_MIN;
int flag = 0;

bool _isValidBST(struct TreeNode* root) {
  if(!root) {
    return true;
  } else if(!root->left && !root->right) {
    if(flag && root->val <= prev)
      return false;
    prev = root->val;
    if(!flag)
        flag = 1;
  } else  {
    if(!_isValidBST(root->left) || (flag && root->val <= prev))
      return false;
    prev = root->val;
    if(!flag)
        flag = 1;
    if(!_isValidBST(root->right))
      return false;
  }
  return true;
}

bool isValidBST(struct TreeNode* root) {
    prev = INT_MIN;
    flag = 0;
}
    return _isValidBST(root);
}
