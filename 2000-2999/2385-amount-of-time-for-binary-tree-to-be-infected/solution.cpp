/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 * Runtime: 77ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int amountOfTime(TreeNode* root, int start) {
    int answer = 0;
    TreeNode* target = nullptr;
    int dist = 0;
    function<int(TreeNode*, TreeNode*)> dfs = [&](TreeNode* n, TreeNode* pa) {
      if (n == nullptr) {
        return 0;
      }
      int h = max(dfs(n->left, n), dfs(n->right, n));

      if (n->val == start) {
        target = pa;
        answer = max(answer, h);
        return 0;
      }

      if (n == target) {
        ++dist;
        target = pa;
        answer = max(answer, dist + h);
        return 0;
      }

      return h + 1;
    };
    dfs(root, nullptr);

    return answer;
  }
};
