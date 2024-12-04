/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canMakeSubsequence(const string& str1, const string& str2) {
    const int n = str1.size();
    const int m = str2.size();

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) {
        if (++j == m) {
          return true;
        }
      }
    }
    return false;
  }
};
