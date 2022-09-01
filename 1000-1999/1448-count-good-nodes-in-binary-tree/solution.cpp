/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * Runtime: 176ms
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
  int goodNodes(TreeNode* root, int maxValue = -0x3f3f3f3f) {
    if (root == nullptr) {
      return 0;
    }

    int good = 0;
    if (root->val >= maxValue) {
      ++good;
    }

    maxValue = max(maxValue, root->val);
    good += goodNodes(root->left, maxValue) + goodNodes(root->right, maxValue);
    return good;
  }
};
