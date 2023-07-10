/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * Runtime: 270ms (92.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    queue<TreeNode*> q;
    q.push(root);

    for (int d = 1; !q.empty(); ++d) {
      int sz = q.size();
      while (sz--) {
        auto u = q.front();
        q.pop();

        if (u->left == nullptr && u->right == nullptr) {
          return d;
        }

        if (u->left) {
          q.push(u->left);
        }
        if (u->right) {
          q.push(u->right);
        }
      }
    }

    return 0;
  }
};
