/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/repeated-substring-pattern/
 * Runtime: 9ms (97.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  inline bool repeatedEvery(const string& s, const int n, const int steps) {
    if (n == steps) {
      return false;
    }
    for (int i = steps; i < n; ++i) {
      if (s[i] != s[i - steps]) {
        return false;
      }
    }
    return true;
  }
public:
  bool repeatedSubstringPattern(const string& s) {
    int n = s.length();
    for (int i = 1; i * i <= n; ++i) {
      if (n % i != 0) {
        continue;
      }
      if (repeatedEvery(s, n, i)) {
        return true;
      }
      if (repeatedEvery(s, n, n / i)) {
        return true;
      }
    }
    return false;
  }
};
