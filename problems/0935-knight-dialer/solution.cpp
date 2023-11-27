/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/knight-dialer/
 * Runtime: 49ms (85.09%)
 */

class Solution {
private:
  const vector<vector<int>> neighbors{
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {0, 3, 9},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4}
  };

  const int mod = 1e9 + 7;
public:
  int knightDialer(int n) {
    vector<unsigned int> pre(10, 1);
    vector<unsigned int> cur(10);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 10; ++j) {
        unsigned int sum = 0;
        for (int k : neighbors[j]) {
          sum += pre[k];
        }
        cur[j] = sum % mod;
      }
      swap(pre, cur);
    }

    int answer = 0;
    for (int x : pre) {
      answer = (answer + x) % mod;
    }
    return answer;
  }
};
