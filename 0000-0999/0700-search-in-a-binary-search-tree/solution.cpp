/**
 * Author: justin0u0<mail@justin0u0c.om>
 * Problem: https://leetcode.com/problems/search-in-a-binary-search-tree/
 * Runtime: 41ms
 */

class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) {
      return nullptr;
    }

    if (root->val == val) {
      return root;
    }

    if (root->val > val) {
      return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
  }
};
