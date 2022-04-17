/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/increasing-order-search-tree
 * Runtime: 0ms
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
  TreeNode* dummy;
  TreeNode* cur;

  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      dfs(root->left);
    }

    cur->right = root;
    cur = cur->right;
    cur->left = nullptr;

    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  TreeNode* increasingBST(TreeNode* root) {
    dummy = new TreeNode;
    cur = dummy;

    dfs(root);

    return dummy->right;
  }
};
