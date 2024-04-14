/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-left-leaves/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int sumOfLeftLeaves(TreeNode* root, bool left = false) {
    if (!root) {
      return 0;
    }
    if (left && !root->left && !root->right) {
      return root->val;
    }
    return sumOfLeftLeaves(root->left, true)
      + sumOfLeftLeaves(root->right, false);
  }
};
