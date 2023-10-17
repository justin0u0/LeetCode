/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/validate-binary-tree-nodes/
 * Runtime: 25ms (96.96%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1) {
        ++indeg[leftChild[i]];
      }
      if (rightChild[i] != -1) {
        ++indeg[rightChild[i]];
      }
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 0) {
        if (root != -1) {
          return false;
        }
        root = i;
      }
    }
    if (root == -1) {
      return false;
    }

    vector<bool> vis(n, false);
    int visit = 0;
    function<bool(int)> dfs = [&](int u) {
      if (vis[u]) {
        return false;
      }
      ++visit;
      vis[u] = true;
      
      int l = leftChild[u];
      if (l != -1 && !dfs(l)) {
        return false;
      }
      int r = rightChild[u];
      if (r != -1 && !dfs(r)) {
        return false;
      }

      return true;
    };

    return dfs(root) && visit == n;
  }
};
