/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
 * Runtime: 192ms (53.96%)
 */

class Solution {
public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    const int n = nums.size();
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    int xorAll = 0;
    for (int num : nums) {
      xorAll ^= num;
    }
    // cout << "xorAll: " << xorAll << endl;

    int diff = INT_MAX;

    function<int(int, int, int, int)> dfs2 = [&](int u, int pa, int block, int xorFirst) {
      if (u == block) {
        return 0;
      }

      int xorChild = nums[u];
      for (int v : graph[u]) {
        if (v != pa) {
          xorChild ^= dfs2(v, u, block, xorFirst);
        }
      }

      if (pa != -1) {
        const int xorParent = xorChild ^ xorFirst ^ xorAll;
        diff = min(diff,
          max(xorFirst, max(xorParent, xorChild)) -
          min(xorFirst, min(xorParent, xorChild)));
      }
      return xorChild;
    };

    function<pair<int, int>(int, int)> dfs1 = [&](int u, int pa) -> pair<int, int> {
      int xorChild = nums[u];
      int nodes = 1;
      for (int v : graph[u]) {
        if (v != pa) {
          auto [x, no] = dfs1(v, u);
          xorChild ^= x;
          nodes += no;
        }
      }

      if (pa != -1 && n - nodes > 1) {
        dfs2(0, -1, u, xorChild);
      }

      return {xorChild, nodes};
    };
    dfs1(0, -1);

    return diff;
  }
};
