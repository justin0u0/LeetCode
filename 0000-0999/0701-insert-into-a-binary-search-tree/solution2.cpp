/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * Runtime: 88ms
 * Description: Iterative
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    TreeNode* cur = root;
    TreeNode* pa = nullptr;
    while (cur != nullptr) {
      if (val < cur->val) {
        pa = cur;
        cur = cur->left;
      } else {
        pa = cur;
        cur = cur->right;
      }
    }

    if (val < pa->val) {
      pa->left = new TreeNode(val);
    } else {
      pa->right = new TreeNode(val);
    }

    return root;
  }
};
