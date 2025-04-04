/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    int maxd = 0;
    TreeNode* lca;
    function<int(TreeNode*, int)> dfs = [&](TreeNode* u, int d) {
      if (u == nullptr) {
        maxd = max(maxd, d);
        return 0;
      }
      const int l = dfs(u->left, d + 1);
      const int r = dfs(u->right, d + 1);
      if (l == r && l + d + 1 == maxd) {
        lca = u;
      }
      return max(l, r) + 1;
    };
    dfs(root, 0);
    return lca;
  }
};
