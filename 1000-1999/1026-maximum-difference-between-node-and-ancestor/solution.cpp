/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 * Runtime: 3ms (97.10%)
 */

class Solution {
private:
  int dfs(TreeNode* root, int minVal, int maxVal) {
    int maxDiff = max(abs(root->val - minVal), abs(root->val - maxVal));
    if (root->left != nullptr) {
      maxDiff = max(maxDiff, dfs(root->left, min(root->val, minVal), max(root->val, maxVal)));
    }
    if (root->right != nullptr) {
      maxDiff = max(maxDiff, dfs(root->right, min(root->val, minVal), max(root->val, maxVal)));
    }
    return maxDiff;
  }
public:
  int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
  }
}
