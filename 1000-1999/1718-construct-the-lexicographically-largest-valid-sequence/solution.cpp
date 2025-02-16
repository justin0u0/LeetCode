/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> constructDistancedSequence(const int n) {
    const int m = 2 * n - 1;
    vector<int> seq(m, 0);
    vector<bool> used(n + 1, false);

    function<bool(int)> dfs = [&](int i) {
      if (i == m) {
        return true;
      }

      if (seq[i] != 0) {
        return dfs(i + 1);
      }

      for (int j = n; j > 1; --j) {
        if (!used[j] && i + j < m && seq[i + j] == 0) {
          seq[i] = j;
          seq[i + j] = j;
          used[j] = true;
          if (dfs(i + 1)) {
            return true;
          }
          seq[i] = 0;
          seq[i + j] = 0;
          used[j] = false;
        }
      }

      if (!used[1]) {
        seq[i] = 1;
        used[1] = true;
        if (dfs(i + 1)) {
          return true;
        }
        seq[i] = 0;
        used[1] = false;
      }

      return false;
    };

    dfs(0);

    return seq;
  }
};
