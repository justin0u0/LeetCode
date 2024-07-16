/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
 * Runtime: 90ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  bool dfs(TreeNode* n, int val, string& path) {
    if (n->val == val) {
      return true;
    }
    if (n->left != nullptr && dfs(n->left, val, path)) {
      path.push_back('L');
    } else if (n->right != nullptr && dfs(n->right, val, path)) {
      path.push_back('R');
    }
    return !path.empty();
  }
public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string s;
    dfs(root, startValue, s);
    string d;
    dfs(root, destValue, d);

    while (!s.empty() && !d.empty() && s.back() == d.back()) {
      s.pop_back();
      d.pop_back();
    }

    return string(s.size(), 'U') + string(d.rbegin(), d.rend());
  }
};
