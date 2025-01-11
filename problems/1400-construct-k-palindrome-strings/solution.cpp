/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-k-palindrome-strings/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canConstruct(const string& s, const int k) {
    int cnt[128] = {};
    for (char c : s) {
      ++cnt[c];
    }

    int pair = 0;
    int left = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      pair += (cnt[c] >> 1) << 1;
      left += (cnt[c] & 1);
    }
    return left <= k && pair + left >= k;
  }
};
