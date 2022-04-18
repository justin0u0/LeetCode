/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Runtime: 18ms
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
  int k;
  int answer;

  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      dfs(root->left);
    }

    if (--k == 0) {
      answer = root->val;
    }

    if (root->right != nullptr) {
      dfs(root->right);
    }
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    this->k = k;
    dfs(root);

    return answer;
  }
};
