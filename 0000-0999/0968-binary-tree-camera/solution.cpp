/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-cameras/
 * Runtime: 17ms
 * Time Complexity: O(N)
 *
 * Description:
 * 	dp(u, 0) -> has camera
 * 		= min(dp(l, 0), dp(l, 1), dp(l, 2)) + min(dp(r, 0), dp(r, 1), dp(r, 2)) + 1
 * 	dp(u, 1) -> no camera, covered by at least 1 child
 * 		= min(dp(l, 0) + dp(r, 1), dp(l, 1) + dp(r, 0), dp(l, 0) + dp(r, 0))
 * 	dp(u, 2) -> no camera, NOT covered by child
 * 		= dp(l, 1) + dp(r, 1)
 *
 * Edge cases (leaf):
 * 	dp(leaf, 0) = 1, dp(leaf, 1) = inf, dp(leaf, 2) = 0
 *
 * Answer:
 * 	min(dp(root, 0), dp(root, 1))
 */

#define min3(a, b, c) min(a, min(b, c))

class Solution {
private:
  const int mask = (1<<10)-1;

  int dp(int val, int i) {
    return (val>>(10 * i)) & mask;
  } 

  int dfs(TreeNode* u) {
    if (u == nullptr) {
      return mask;
    }

    int l = dfs(u->left);
    int r = dfs(u->right);

    int dp0 = min3(dp(l, 0), dp(l, 1), dp(l, 2)) + min3(dp(r, 0), dp(r, 1), dp(r, 2)) + 1;
    int dp1 = min3(dp(l, 0) + dp(r, 1), dp(l, 1) + dp(r, 0), dp(l, 0) + dp(r, 0));
    int dp2 = dp(l, 1) + dp(r, 1);

    // cout << min(dp0, mask) << ' ' << min(dp1, mask) << ' ' << min(dp2, mask) << endl;
    return (min(dp2, mask)<<20) + (min(dp1, mask)<<10) + min(dp0, mask);
  }
public:
  int minCameraCover(TreeNode* root) {
    int val = dfs(root);
    return min(dp(val, 0), dp(val, 1));
  }
};

