/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
 * Runtime: 42ms (99.57%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minSwaps(string& s) {
    int swaps = 0;

    int l = 0;
    int r = 0;
    int i = 0;
    int j = s.length() - 1;
    while (i <= j) {
      for (; i <= j; ++i) {
        if (s[i] == '[') {
          ++l;
        } else if (l != 0) {
          --l;
        } else {
          break;
        }
      }
      for (; i <= j; --j) {
        if (s[j] == ']') {
          ++r;
        } else if (r != 0) {
          --r;
        } else {
          break;
        }
      }
      if (i > j) {
        break;
      }
      swap(s[i], s[j]);
      ++swaps;
    }

    return swaps;
  }
};
