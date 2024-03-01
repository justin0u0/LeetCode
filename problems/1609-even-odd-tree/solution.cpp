/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/even-odd-tree/
 * Runtime: 136ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    bool even = true;
    while (!q.empty()) {
      int sz = q.size();

      TreeNode* pre = nullptr;
      while (sz--) {
        TreeNode* cur = q.front();
        if (even == ((cur->val & 1) == 0)) { // xnor
          return false;
        }
        if (pre != nullptr && ((even && pre->val >= cur->val) || (!even && pre->val <= cur->val))) {
          return false;
        }
        q.pop();
        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
        pre = cur;
      }

      even ^= 1;
    }
    return true;
  }
};
