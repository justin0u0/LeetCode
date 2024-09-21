/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/balanced-binary-tree/
 * Runtime: 7ms (78.35%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    function<pair<int, bool>(TreeNode*)> dfs = [&](TreeNode* n) -> pair<int, bool> {
      if (n == nullptr) {
        return {0, true};
      }
      auto [lh, lok] = dfs(n->left);
      auto [rh, rok] = dfs(n->right);
      return {max(lh, rh) + 1, lok && rok && abs(lh - rh) <= 1};
    };
    return dfs(root).second;
  }
};
