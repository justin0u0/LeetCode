/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
  int dfs(TreeNode* u, int sum) {
    sum = (sum << 1) + u->val;

    if (u->left == nullptr && u->right == nullptr)
      return sum;
    if (u->left == nullptr)
      return dfs(u->right, sum);
    if (u->right == nullptr)
      return dfs(u->left, sum);
    return dfs(u->left, sum) + dfs(u->right, sum);
  }
public:
  int sumRootToLeaf(TreeNode* root) {
    return dfs(root, 0);
  }
};
