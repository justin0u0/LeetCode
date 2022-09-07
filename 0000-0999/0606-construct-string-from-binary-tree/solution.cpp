/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-string-from-binary-tree/
 * Runtime: 19ms
 */

class Solution {
private:
  string s;

  void dfs(TreeNode* root) {
    s.append(to_string(root->val));
    if (root->left == nullptr && root->right == nullptr) {
      return;
    }

    s.push_back('(');
    if (root->left != nullptr) {
      dfs(root->left);
    }
    s.push_back(')');

    if (root->right != nullptr) {
      s.push_back('(');
      dfs(root->right);
      s.push_back(')');
    }
  }
public:
  string tree2str(TreeNode* root) {
    s = "";
    dfs(root);
    return s;
  }
};
