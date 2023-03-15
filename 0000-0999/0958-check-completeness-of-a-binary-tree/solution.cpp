/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool done = false;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        TreeNode* u = q.front();
        q.pop();
        if (done && u != nullptr) {
          return false;
        }

        if (u == nullptr) {
          done = true;
          continue;
        }

        q.push(u->left);
        q.push(u->right);
      }
    }

    return true;
  }
}
