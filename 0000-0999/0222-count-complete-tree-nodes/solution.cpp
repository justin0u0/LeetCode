/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-complete-tree-nodes/
 * Runtime: 16ms (99.96%)
 */

class Solution {
public:
  int countNodes(TreeNode* root) {
    int depth = 0;
    for (TreeNode* cur = root; cur != nullptr; cur = cur->left) {
      ++depth;
    }

    if (depth <= 1) {
      return depth;
    }

    const int base = 1 << (depth - 2);
    int l = 1 << (depth - 1);
    int r = 1 << depth;
    while (l < r) {
      int mid = (l + r) >> 1;

      TreeNode* cur = root;
      for (int i = base; i > 0; i >>= 1) {
        if (mid & i) {
          cur = cur->right;
        } else {
          cur = cur->left;
        }
      }

      if (cur == nullptr) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return l - 1;
  }
};
