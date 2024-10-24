/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flip-equivalent-binary-trees/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return true;
    }
    if (root1 != nullptr && root2 != nullptr) {
      if (root1->val == root2->val) {
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
          || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
      }
    }
    return false;
  }
};
