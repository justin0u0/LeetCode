/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/time-needed-to-inform-all-employees/
 * Runtime: 147ms (99.71%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    function<void(int)> dfs = [&](int u) {
      int& m = manager[u];
      if (m == -1) {
        return;
      }

      dfs(m);

      int& t = informTime[u];
      t += informTime[m];
      m = -1;
    };

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      int t = informTime[i];
      dfs(i);
      answer = max(answer, informTime[i] - t);
    }
    return answer;
  }
};
