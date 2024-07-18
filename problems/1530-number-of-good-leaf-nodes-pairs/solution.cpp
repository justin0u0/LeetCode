/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
 * Runtime: 23ms (99.84%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countPairs(TreeNode* root, int distance) {
    int pairs = 0;
    function<array<int, 10>(TreeNode*)> dfs = [&](TreeNode* n) {
      if (n->left == nullptr && n->right == nullptr) {
        return array<int, 10>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      }

      array<int, 10> l{0};
      array<int, 10> r{0};
      if (n->left != nullptr) {
        l = dfs(n->left);
      }
      if (n->right != nullptr) {
        r = dfs(n->right);
      }
      for (int i = 9; i > 0; --i) {
        l[i] = l[i - 1];
        r[i] = r[i - 1];
      }
      l[0] = 0;
      r[0] = 0;

      for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
          if (i + j <= distance) {
            pairs += l[i] * r[j];
          }
        }
      }

      for (int i = 0; i < 10; ++i) {
        l[i] += r[i];
      }
      return l;
    };
    dfs(root);

    return pairs;
  }
};
