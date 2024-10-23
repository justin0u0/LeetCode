/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/cousins-in-binary-tree-ii/
 * Runtime: 15ms (97.55%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    root->val = 0;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();
      int sum = 0;
      while (sz--) {
        auto u = q.front();
        q.pop();

        if (u->left != nullptr) {
          sum += u->left->val;
        }
        if (u->right != nullptr) {
          sum += u->right->val;
        }
        q.push(u);
      }

      sz = q.size();
      while (sz--) {
        auto u = q.front();
        q.pop();

        int val = sum;
        if (u->left != nullptr) {
          val -= u->left->val;
          q.push(u->left);
        }
        if (u->right != nullptr) {
          val -= u->right->val;
          q.push(u->right);
        }
        if (u->left != nullptr) {
          u->left->val = val;
        }
        if (u->right != nullptr) {
          u->right->val = val;
        }
      }
    }
    return root;
  }
};
