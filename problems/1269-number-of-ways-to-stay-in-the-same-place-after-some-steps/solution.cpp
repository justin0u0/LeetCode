/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
 * Runtime: 6ms (96.54%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
  int pre[501];
  int cur[501];
public:
  int numWays(int steps, int arrLen) {
    if (arrLen == 1) {
      return 1;
    }

    memset(pre, 0, sizeof(pre));
    memset(cur, 0, sizeof(cur));
    pre[0] = 1;

    int n = min(steps, arrLen);
    for (int i = 0; i < steps; ++i) {
      cur[0] = (pre[0] + pre[1]) % mod;
      cur[n - 1] = (pre[n - 1] + pre[n - 2]) % mod;
      for (int j = 1; j < n - 1; ++j) {
        cur[j] = ((pre[j - 1] + pre[j]) % mod + pre[j + 1]) % mod;
      }
      swap(pre, cur);
    }
    
    return pre[0];
  }
};
