/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Runtime: 40ms
 * Description:
 *  A path will always have a root.
 *  dp(i) -> maximum path with root = i
 *  dp(i) = val(i) + max(dp(i->left) + dp(i->right))
 *  maxpath = max(val(i) + dp(i->left) + dp(i->right))
 */

class Solution {
private:
  int dfs(TreeNode* root, int& answer) {
    int l = 0;
    int r = 0;
    if (root->left != nullptr) {
      l = max(l, dfs(root->left, answer));
    }
    if (root->right != nullptr) {
      r = max(r, dfs(root->right, answer));
    }

    answer = max(answer, root->val + l + r);

    return root->val + max(l, r);
  }
public:
  int maxPathSum(TreeNode* root) {
    int answer = -1e9;
    dfs(root, answer);

    return answer;
  }
};

