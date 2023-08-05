/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Runtime: 12ms (91.60%)
 */

class Solution {
private:
  vector<TreeNode*> dfs(int l, int r) {
    if (l > r) {
      return vector<TreeNode*>{nullptr};
    }

    vector<TreeNode*> box;
    for (int i = l; i <= r; ++i) {
      const vector<TreeNode*> lns = dfs(l, i - 1);
      const vector<TreeNode*> rns = dfs(i + 1, r);
      for (TreeNode* ln : lns) {
        for (TreeNode* rn : rns) {
          box.emplace_back(new TreeNode(i, ln, rn));
        }
      }
    }
    return box;
  }
public:
  vector<TreeNode*> generateTrees(int n) {
    return dfs(1, n);
  }
};
