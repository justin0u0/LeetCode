/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/evaluate-boolean-binary-tree/
 * Runtime: 2ms (99.52%)
 */

class Solution {
public:
  bool evaluateTree(TreeNode* root) {
    switch (root->val) {
      case 0:
        return false;
      case 1:
        return true;
      case 2:
        return evaluateTree(root->left) || evaluateTree(root->right);
      case 3:
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
    return false;
  }
};
