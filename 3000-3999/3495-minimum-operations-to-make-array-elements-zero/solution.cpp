/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
 * Runtime: 23ms (61.59%)
 */

class Solution {
public:
  long long minOperations(vector<vector<int>>& queries) {
    long long total = 0;
    for (const auto& query : queries) {
      long long ops = 0;
      for (int i = 1, j = 1; i <= query[1]; i <<= 2, ++j) {
        int l = i;
        int r = (i << 2) - 1;
        if (r < query[0]) {
          continue;
        }

        l = max(l, query[0]);
        r = min(r, query[1]);
        ops += (long long)(r - l + 1) * j;
      }
      total += (ops + 1) / 2;
    }
    return total;
  }
};
