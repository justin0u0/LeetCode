/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * Runtime: 147ms (98.61%)
 */

class Solution {
private:
  int answer;

  int dfs(TreeNode* root, bool dir) {
    if (root == nullptr) {
      return 0;
    }

    if (dir) {
      answer = max(answer, dfs(root->left, dir));
      return dfs(root->right, !dir) + 1;
    }
    answer = max(answer, dfs(root->right, dir));
    return dfs(root->left, !dir) + 1;
  }
public:
  int longestZigZag(TreeNode* root) {
    answer = 0;
    int d1 = dfs(root->right, false);
    int d2 = dfs(root->left, true);
    return max(answer, max(d1, d2));
  }
}
