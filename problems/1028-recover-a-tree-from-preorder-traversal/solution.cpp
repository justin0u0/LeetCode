/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
 * Runtime: 3ms (62.80%)
 */

class Solution {
public:
  TreeNode* recoverFromPreorder(const string& traversal) {
    const int n = traversal.size();

    int cursor = 0;

    function<TreeNode*(int)> dfs = [&](int depth) {
      int val = 0;

      for (int& i = cursor; i < n && traversal[i] >= '0' && traversal[i] <= '9'; ++i) {
        val = val * 10 + traversal[i] - '0';
      }

      TreeNode* tn = new TreeNode(val);
      
      int d = 0;
      for (int i = cursor; i < n && traversal[i] == '-'; ++i) {
        ++d;
      }
      if (d == depth + 1) {
        cursor += d;
        tn->left = dfs(depth + 1);
      }

      d = 0;
      for (int i = cursor; i < n && traversal[i] == '-'; ++i) {
        ++d;
      }
      if (d == depth + 1) {
        cursor += d;
        tn->right = dfs(depth + 1);
      }

      return tn;
    };

    return dfs(0);
  }
};
