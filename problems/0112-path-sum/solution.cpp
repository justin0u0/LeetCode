/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-sum/
 * Runtime: 17ms
 */

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == root->val;
    }

    if (root->left != nullptr && hasPathSum(root->left, targetSum - root->val)) {
      return true;
    }
    
    if (root->right != nullptr && hasPathSum(root->right, targetSum - root->val)) {
      return true;
    }

    return false;
  }
};
