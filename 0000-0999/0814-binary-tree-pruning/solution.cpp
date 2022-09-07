/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-pruning/
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
  bool prune(TreeNode* root) {
    bool p = (root->val == 0);
    if (root->left != nullptr && !prune(root->left)) {
      p = false;
    } else {
      root->left = nullptr;
    }
    if (root->right != nullptr && !prune(root->right)) {
      p = false;
    } else {
      root->right = nullptr;
    }

    return p;
  }
public:
  TreeNode* pruneTree(TreeNode* root) {
    if (prune(root)) {
      return nullptr;
    }

    return root;
  }
};
