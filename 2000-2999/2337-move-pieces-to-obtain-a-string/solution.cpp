/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/move-pieces-to-obtain-a-string/
 * Runtime: 7ms (77.01%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canChange(const string& start, const string& target) {
    const int n = start.length();

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (start[i] == '_') {
        continue;
      }

      while (j < n && target[j] == '_') {
        ++j;
      }
      if (j == n ||
        start[i] != target[j] ||
        (start[i] == 'L' && i < j) ||
        (start[i] == 'R' && i > j)
      ) {
        return false;
      }
      ++j;
    }

    while (j < n && target[j] == '_') {
      ++j;
    }

    return j == n;
  }
};
