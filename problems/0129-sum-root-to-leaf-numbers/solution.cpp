/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int sum;

  void dfs(TreeNode* root, int num) {
    int val = num * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      sum += val;
      return;
    }

    if (root->left != nullptr) {
      dfs(root->left, val);
    }
    if (root->right != nullptr) {
      dfs(root->right, val);
    }
  }
public:
  int sumNumbers(TreeNode* root) {
    sum = 0;
    dfs(root, 0);
    return sum;
  }
};
