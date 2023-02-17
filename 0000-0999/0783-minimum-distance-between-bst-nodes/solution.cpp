/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int minDiff;
  int last;

  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      dfs(root->left);
    }

    if (last != -1) {
      minDiff = min(minDiff, abs(root->val - last));
    }
    last = root->val;

    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  int minDiffInBST(TreeNode* root) {
    minDiff = INT_MAX;
    last = -1;
    dfs(root);
    return minDiff;
  }
};
