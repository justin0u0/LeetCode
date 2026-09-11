/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-3-digit-even-numbers/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int totalNumbers(vector<int>& digits) {
    const int n = digits.size();

    vector<bool> vis(1000, false);
    int total = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || digits[i] == 0) {
          continue;
        }
        for (int k = 0; k < n; ++k) {
          if (i == k || j == k || (digits[k] & 1)) {
            continue;
          }

          const auto x = digits[i] * 100 + digits[j] * 10 + digits[k];
          if (!vis[x]) {
            vis[x] = true;
            ++total;
          }
        }
      }
    }

    return total;
  }
};
