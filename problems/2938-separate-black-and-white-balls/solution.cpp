/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/separate-black-and-white-balls/
 * Runtime: 13ms (99.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long minimumSteps(const string& s) {
    int j = s.length() - 1;
    long long steps = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] == '1') {
        steps += j - i;
        --j;
      }
    }
    return steps;
  }
};
