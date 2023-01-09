/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  vector<int> answer;

  void dfs(TreeNode* root) {
    answer.emplace_back(root->val);
    if (root->left != nullptr) {
      dfs(root->left);
    }
    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return vector<int>{};
    }
    answer.clear();
    dfs(root);
    return answer;
  }
};
