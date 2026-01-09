/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
 * Runtime: 0ms (100.00%)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    function<int(TreeNode*)> dfs1 = [&](TreeNode* n) {
      if (n == nullptr) {
        return 0;
      }
      return max(dfs1(n->left), dfs1(n->right)) + 1;
    };
    const int depth = dfs1(root);

    function<TreeNode*(TreeNode*, int)> dfs2 = [&](TreeNode* n, int d) {
      if (n == nullptr) {
        return n;
      }
      if (d == depth) {
        return n;
      }
      const auto left = dfs2(n->left, d + 1);
      const auto right = dfs2(n->right, d + 1);
      if (left != nullptr && right != nullptr) {
        return n;
      }
      if (left != nullptr) {
        return left;
      }
      return right;
    };
    return dfs2(root, 1);
  }
};
