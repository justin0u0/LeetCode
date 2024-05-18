/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/distribute-coins-in-binary-tree/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int distributeCoins(TreeNode* root) {
    int moves = 0;
    function<int(TreeNode*)> dfs = [&](TreeNode* n) {
      if (n == nullptr) {
        return 0;
      }
      int d = dfs(n->left) + dfs(n->right) + n->val - 1;
      moves += abs(d);
      return d;
    };
    dfs(root);
    return moves;
  }
};
