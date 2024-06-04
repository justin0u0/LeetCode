/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-palindrome/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestPalindrome(const string& s) {
    int sets = 0;
    bool set[128] = {0};
    int answer = 0;
    for (char c : s) {
      if (set[c]) {
        ++answer;
        --sets;
        set[c] = 0;
      } else {
        ++sets;
        set[c] = 1;
      }
    }
    answer <<= 1;
    if (sets != 0) {
      ++answer;
    }
    return answer;
  }
};
