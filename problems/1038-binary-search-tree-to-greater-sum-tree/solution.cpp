/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * Runtime: 0ms
 */

class Solution {
private:
  int sum;

  void dfs(TreeNode* root) {
    if (root->right != nullptr) {
      dfs(root->right);
    }
    int val = root->val;
    root->val += sum;
    sum += val;

    if (root->left != nullptr) {
      dfs(root->left);
    }
  }
public:
  TreeNode* bstToGst(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    sum = 0;
    dfs(root);

    return root;
  }
};

