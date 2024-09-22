/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-paths/
 * Runtime: 3ms (63.81%)
 */

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;

    function<void(TreeNode*, string)> dfs = [&](TreeNode* n, string s) {
      if (n->left == nullptr && n->right == nullptr) {
        res.emplace_back(s + to_string(n->val));
        return;
      }
      if (n->left != nullptr) {
        dfs(n->left, s + to_string(n->val) + "->");
      }
      if (n->right != nullptr) {
        dfs(n->right, s + to_string(n->val) + "->");
      }
    };
    dfs(root, "");

    return res;
  }
};
