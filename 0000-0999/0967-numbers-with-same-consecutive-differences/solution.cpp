/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
 * Runtime: 0ms
 */

class Solution {
private:
  vector<int> answer;

  void dfs(int n, int k, int val) {
    if (n == 0) {
      answer.emplace_back(val);
      return;
    }

    int r = val % 10;
    if (r + k < 10) {
      dfs(n - 1, k, val * 10 + (r + k));
    }
    if (k != 0 && r - k >= 0) {
      dfs(n - 1, k, val * 10 + (r - k));
    }
  }
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    answer.clear();
    for (int i = 1; i <= 9; ++i) {
      dfs(n - 1, k, i);
    }

    return answer;
  }
};
