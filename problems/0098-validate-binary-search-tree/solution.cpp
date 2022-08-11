/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/validate-binary-search-tree/
 * Runtime: 18ms
 */

class Solution {
private:
  TreeNode* prev;

  bool dfs(TreeNode* root) {
    if (root->left != nullptr && !dfs(root->left)) {
      return false;
    }

    if (prev != nullptr && prev->val >= root->val) {
      return false;
    }
    prev = root;

    if (root->right != nullptr && !dfs(root->right)) {
      return false;
    }

    return true;
  }
public:
  bool isValidBST(TreeNode* root) {
    prev = nullptr;
    return dfs(root);
  }
};
