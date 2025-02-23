/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    const int n = preorder.size();

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m.emplace(postorder[i], i);
    }

    int p = 0;

    function<TreeNode*(int)> dfs = [&](int pos) -> TreeNode* {
      if (p >= n) {
        return nullptr;
      }

      const int v = preorder[p];
      if (m.at(v) > pos) {
        return nullptr;
      }

      p++;

      TreeNode* tn = new TreeNode(v);
      tn->left = dfs(m.at(v));
      tn->right = dfs(m.at(v));

      return tn;
    };

    return dfs(INT_MAX);
  }
};
