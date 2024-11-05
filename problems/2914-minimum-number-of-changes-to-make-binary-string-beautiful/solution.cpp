/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minChanges(string& s) {
    s.push_back('$');

    char cur = '^';
    int count = 0;
    int changes = 0;
    for (char c : s) {
      if (c == cur) {
        ++count;
      } else if (count & 1) {
        ++changes;
        cur = c ^ 1;
        count = 0;
      } else {
        cur = c;
        count = 1;
      }
    }
    return changes;
  }
};
