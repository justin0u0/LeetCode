/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximal-network-rank/
 * Runtime: 37ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximalNetworkRank(int n, const vector<vector<int>>& roads) {
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    vector<int> degs(n, 0);
    for (const auto& r : roads) {
      edges[r[0]][r[1]] = true;
      edges[r[1]][r[0]] = true;
      ++degs[r[0]];
      ++degs[r[1]];
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        answer = max(answer, degs[i] + degs[j] - edges[i][j]);
      }
    }
    return answer;
  }
};
