/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
  vector<int> answer;

  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      dfs(root->left);
    }
    answer.emplace_back(root->val);
    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  vector<int> inorderTraversal(TreeNode* root) {
    answer.clear();
    if (root == nullptr) {
      return answer;
    }

    dfs(root);
    return answer;
  }
};
