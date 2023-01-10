/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/same-tree/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr || q == nullptr)
      return false;
    else if (p->val != q->val)
      return false;
    else
      return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};
