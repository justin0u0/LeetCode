/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Runtime: 34ms
 */

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};
