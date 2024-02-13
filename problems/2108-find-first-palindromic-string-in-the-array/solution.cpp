/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
 * Runtime: 27ms (99.39%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  inline bool isPalindrome(const string& s) {
    const int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
      if (s[i] != s[len - i - 1]) {
        return false;
      }
    }
    return true;
  }
public:
  string firstPalindrome(const vector<string>& words) {
    for (const auto& w : words) {
      if (isPalindrome(w)) {
        return w;
      }
    }
    return "";
  }
};
