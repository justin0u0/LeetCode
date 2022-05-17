/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 * Runtine: 619ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (original->val == target->val) {
      return cloned;
    }

    if (original->left != nullptr) {
      TreeNode* n = getTargetCopy(original->left, cloned->left, target);
      if (n != nullptr) {
        return n;
      }
    }
    if (original->right != nullptr) {
      TreeNode* n = getTargetCopy(original->right, cloned->right, target);
      if (n != nullptr) {
        return n;
      }
    }

    return nullptr;
  }
};
