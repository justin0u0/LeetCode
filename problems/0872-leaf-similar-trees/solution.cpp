/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/leaf-similar-trees/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  void dfs(TreeNode* t, vector<int>& leaves) {
    if (t->left == nullptr && t->right == nullptr) {
      leaves.emplace_back(t->val);
    }
    if (t->left != nullptr) {
      dfs(t->left, leaves);
    }
    if (t->right != nullptr) {
      dfs(t->right, leaves);
    }
  }
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> l1, l2;
    dfs(root1, l1);
    dfs(root2, l2);
    return l1 == l2;
  }
};
