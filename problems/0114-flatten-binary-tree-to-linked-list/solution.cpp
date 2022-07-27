/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Runtime: 8ms
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
private:
  TreeNode* pre;

  void dfs(TreeNode* n) {
    pre->right = n;
    pre = n;

    TreeNode* r = n->right;
    if (n->left != nullptr) {
      dfs(n->left);
    }
    n->left = nullptr;
    if (r != nullptr) {
      dfs(r);
    }
  }
public:
  void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    TreeNode* dummy = new TreeNode;
    pre = dummy;
    dfs(root);
    delete dummy;
  }
};
