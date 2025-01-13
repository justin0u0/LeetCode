/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-length-of-string-after-operations/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumLength(const string& s) {
    int cnt[128] = {0};
    for (char c : s) {
      ++cnt[c];
    }

    int sum = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (cnt[c] > 0) {
        sum += 2 - (cnt[c] & 1);
      }
    }
    return sum;
  }
};
