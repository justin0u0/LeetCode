/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-from-removing-substrings/
 * Runtime: 32ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumGain(string& s, int x, int y) {
    // Assume x > y, then we prioritize "ab" over "ba".
    //
    // For each 'a', we keep if for future 'b'.
    //
    // For each 'b', we match previous 'a' if there is any. Otherwise, we keep
    // it for future "ba" pairs.

    char c = 'a'; // targer character to keep
    if (x < y) {
      swap(x, y);
      c = 'b';
    }

    // We add a dummy character so calculation on "ba" pairs is triggered at
    // the end.
    s += 'z';

    int a = 0;
    int b = 0;
    int gain = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != 'a' && s[i] != 'b') {
        gain += min(a, b) * y;
        a = 0;
        b = 0;
        continue;
      }

      if (s[i] == c) {
        ++a;
      } else if (a != 0) {
        --a;
        gain += x;
      } else {
        ++b;
      }
    }

    return gain;
  }
};
