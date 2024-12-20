/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
 * Runtime: 3ms (50.72%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    vector<TreeNode*> pre;
    vector<TreeNode*> next;
    vector<TreeNode*> cur;

    for (int level = 0; !q.empty(); ++level) {
      size_t sz = q.size();

      next.clear();
      cur.clear();

      while (sz--) {
        TreeNode* u = q.front();
        q.pop();

        cur.push_back(u);
        next.push_back(u);

        if (u->left != nullptr) {
          q.push(u->left);
          q.push(u->right);
        }
      }

      if (level & 1) {
        reverse(cur.begin(), cur.end());
      } else {
        reverse(pre.begin(), pre.end());
      }

      auto it = cur.begin();

      for (TreeNode* u : pre) {
        u->left = (*it);
        ++it;
        u->right = (*it);
        ++it;
      }

      pre = next;
    }

    return root;
  }
};
