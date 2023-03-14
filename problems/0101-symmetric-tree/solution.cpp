/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/symmetric-tree/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  bool dfs(TreeNode* l, TreeNode* r) {
    if (l == nullptr && r == nullptr) {
      return true;
    }
    if (l == nullptr || r == nullptr) {
      return false;
    }
    return l->val == r->val && dfs(l->left, r->right) && dfs(l->right, r->left);
  }
public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }

    return dfs(root->left, root->right);
  }
}
