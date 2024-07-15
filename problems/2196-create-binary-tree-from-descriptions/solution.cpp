/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/create-binary-tree-from-descriptions/
 * Runtime: 568ms (96.73%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  unordered_map<int, pair<TreeNode*, bool>> nodes;

  inline pair<TreeNode*, bool>& makeNode(int x) {
    if (nodes.find(x) == nodes.end()) {
      nodes.emplace(x, pair{new TreeNode(x), true});
    }
    return nodes[x];
  }
public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    nodes.clear();

    for (const auto& desc : descriptions) {
      auto& p = makeNode(desc[0]);
      auto& c = makeNode(desc[1]);
      c.second = false;
      if (desc[2]) {
        p.first->left = c.first;
      } else {
        p.first->right = c.first;
      }
    }

    for (const auto& desc : descriptions) {
      auto [n, root] = nodes[desc[0]];
      if (root) {
        return n;
      }
    }
    return nullptr;
  }
};
