/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
 * Runtime: 46ms (28.67%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numOfWays(int n) {
    int trans[27][27] = {0};
    for (int i = 0; i < 27; ++i) {
      for (int j = 0; j < 27; ++j) {
        if (i / 9 == j / 9 || i / 3 % 3 == j / 3 % 3 || i % 3 == j % 3) {
          continue;
        }
        trans[i][j] = 1;
      }
    }

    vector<bool> ok(27, false);
    vector<int> curr(27, 0);
    vector<int> next(27, 0);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (i != j && j != k) {
            const int x = i * 9 + j * 3 + k;
            curr[x] = 1;
            ok[x] = true;
          }
        }
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 27; ++j) {
        if (!ok[j]) {
          continue;
        }
        next[j] = 0;
        for (int k = 0; k < 27; ++k) {
          if (!ok[k]) {
            continue;
          }
          next[j] = (next[j] + (long long)trans[j][k] * curr[k] % mod) % mod;
        }
      }
      curr = next;
    }

    int sum = 0;
    for (int i = 0; i < 27; ++i) {
      sum = (sum + curr[i]) % mod;
    }
    return sum;
  }
};
