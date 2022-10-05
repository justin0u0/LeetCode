/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-one-row-to-tree/
 * Runtime: 16ms (96.69%)
 */

class Solution {
private:
  void solve(TreeNode* u, int val, int depth) {
    if (depth == 2) {
      TreeNode* l = new TreeNode(val);
      l->left = u->left;
      u->left = l;
      TreeNode* r = new TreeNode(val);
      r->right = u->right;
      u->right = r;
      return;
    }

    if (u->left != nullptr) {
      solve(u->left, val, depth - 1);
    }
    if (u->right != nullptr) {
      solve(u->right, val, depth - 1);
    }
  }
public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      TreeNode* u = new TreeNode(val);
      u->left = root;
      return u;
    }

    solve(root, val, depth);
    return root;
  }
};
