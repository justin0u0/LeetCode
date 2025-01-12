/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
 * Runtime: 14ms (55.08%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canBeValid(const string& s, const string& locked) {
    const int n = s.length();
    if (n & 1) {
      return false;
    }

    {
      int unsure = 0;
      int left = 0;
      int right = 0;
      for (int i = 0; i < n; ++i) {
        if (locked[i] == '0') {
          ++unsure;
        } else if (s[i] == '(') {
          ++left;
        } else {
          ++right;
        }
        if (left + unsure < right) {
          return false;
        }
      }
    }

    {
      int unsure = 0;
      int left = 0;
      int right = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '0') {
          ++unsure;
        } else if (s[i] == '(') {
          ++left;
        } else {
          ++right;
        }
        if (right + unsure < left) {
          return false;
        }
      }
    }

    return true;
  }
};
