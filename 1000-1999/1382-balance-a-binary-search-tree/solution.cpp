/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/balance-a-binary-search-tree/
 * Runtime: 61ms (97.46%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> arr;
    
    function<void(TreeNode*)> dfs = [&](TreeNode* n) {
      if (n->left != nullptr) {
        dfs(n->left);
      }
      arr.emplace_back(n);
      if (n->right != nullptr) {
        dfs(n->right);
      }
    };
    dfs(root);

    function<TreeNode*(int, int)> build = [&](int l, int r) -> TreeNode* {
      if (l >= r) {
        return nullptr;
      }
      int mid = (l + r) >> 1;
      TreeNode* n = arr[mid];
      n->left = build(l, mid);
      n->right = build(mid + 1, r);
      return n;
    };
    return build(0, arr.size());
  }
};
