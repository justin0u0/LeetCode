/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * Runtime: 4ms (80.20%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  unordered_map<TreeNode*, TreeNode*> parent;

  void build(TreeNode* root, TreeNode* pa) {
    parent[root] = pa;
    if (root->left) {
      build(root->left, root);
    }
    if (root->right) {
      build(root->right, root);
    }
  }

  void dfs(TreeNode* u, TreeNode* last, int k, vector<int>& result) {
    if (k == 0) {
      result.emplace_back(u->val);
      return;
    }
    
    if (u->left && u->left != last) {
      dfs(u->left, u, k - 1, result);
    }
    if (u->right && u->right != last) {
      dfs(u->right, u, k - 1, result);
    }

    auto p = parent[u];
    if (p && p != last) {
      dfs(p, u, k - 1, result);
    }
  }
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    parent.clear();
    build(root, nullptr);

    vector<int> answer;
    dfs(target, nullptr, k, answer);
    return answer;
  }
};
