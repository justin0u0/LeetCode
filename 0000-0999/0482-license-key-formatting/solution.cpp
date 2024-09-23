/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/license-key-formatting/
 * Runtime: 3ms (97.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string licenseKeyFormatting(string& s, int k) {
    int j = 0;
    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        s[j++] = c - 'a' + 'A';
      } else if (c != '-') {
        s[j++] = c;
      }
    }

    s.resize(j);
    const int n = s.length();
    string res;
    res.reserve(n + k);

    int cur = 0;
    for (int i = 0; i < n % k; ++i) {
      res.push_back(s[cur++]);
    }
    for (int i = 0; i < n / k; ++i) {
      if (!res.empty()) {
        res.push_back('-');
      }
      for (int j = 0; j < k; ++j) {
        res.push_back(s[cur++]);
      }
    }
    return res;
  }
};
