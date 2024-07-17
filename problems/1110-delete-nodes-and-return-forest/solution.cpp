/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-nodes-and-return-forest/
 * Runtime: 11ms (88.65%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
    unordered_set<int> del;
    for (int d : toDelete) {
      del.emplace(d);
    }

    vector<TreeNode*> forest;

    function<bool(TreeNode*, bool)> dfs = [&](TreeNode* n, bool root) {
      bool rm = del.find(n->val) != del.end();
      if (root && !rm) {
        forest.emplace_back(n);
      }
      if (n->left != nullptr && dfs(n->left, rm)) {
        n->left = nullptr;
      }
      if (n->right != nullptr && dfs(n->right, rm)) {
        n->right = nullptr;
      }
      return rm;
    };
    dfs(root, true);

    return forest;
  }
};
