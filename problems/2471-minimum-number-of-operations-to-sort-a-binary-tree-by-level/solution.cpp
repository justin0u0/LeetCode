/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
 * Runtime: 63ms (88.27%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumOperations(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int ops = 0;

    while (!q.empty()) {
      const int sz = q.size();
      vector<int> rows(sz);
      for (int i = 0; i < sz; ++i) {
        TreeNode* u = q.front();
        q.pop();

        rows[i] = u->val;

        if (u->left != nullptr) {
          q.push(u->left);
        }
        if (u->right != nullptr) {
          q.push(u->right);
        }
      }

      vector<int> sorted = rows;
      sort(sorted.begin(), sorted.end());
      for (int i = 0; i < sz; ) {
        int j = lower_bound(sorted.begin(), sorted.end(), rows[i]) - sorted.begin();
        if (i != j) {
          swap(rows[i], rows[j]);
          ++ops;
        } else {
          ++i;
        }
      }
    }

    return ops;
  }
};
