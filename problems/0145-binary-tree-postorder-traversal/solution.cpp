/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> po;

    function<void(TreeNode*)> dfs = [&](TreeNode* n) {
      if (n->left != nullptr) {
        dfs(n->left);
      }
      if (n->right != nullptr) {
        dfs(n->right);
      }
      po.emplace_back(n->val);
    };
    dfs(root);
    return po;
  }
};
