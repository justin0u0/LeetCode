/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    vector<bool> b(n + 1, false);
    for (int num : banned) {
      if (num <= n) {
        b[num] = true;
      }
    }

    int sum = 0;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      if (!b[i]) {
        sum += i;
        if (sum > maxSum) {
          break;
        }
        ++count;
      }
    }
    return count;
  }
};
