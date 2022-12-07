/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-of-bst/
 * Runtime: 144ms (86.96%)
 */

class Solution {
public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    if (root->left != nullptr) {
      sum += rangeSumBST(root->left, low, high);
    }
    if (root->right != nullptr) {
      sum += rangeSumBST(root->right, low, high);
    }

    if (root->val < low || root->val > high) {
      return sum;
    }

    return sum + root->val;
  }
};
