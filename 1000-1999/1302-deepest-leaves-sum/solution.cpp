/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/deepest-leaves-sum/
 * Runtime: 103ms
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
  int deepestLeavesSum(TreeNode* root) {
    int sum = 0;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      sum = 0;

      int sz = (int)q.size();
      while (sz--) {
        TreeNode* cur = q.front();
        q.pop();

        sum += cur->val;
        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
      }
    }

    return sum;
  }
};
