/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 * Runtime: 43ms
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numRollsToTarget(int n, int k, int target) {
    int* cur = new int[target + 1]();
    int* pre = new int[target + 1]();
    pre[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        for (int u = target; u >= j; --u) {
          cur[u] = (cur[u] + pre[u - j]) % mod;
        }
      }
      swap(cur, pre);
      memset(cur, 0, (target + 1) * sizeof(int));
    }

    return pre[target];
  }
};
