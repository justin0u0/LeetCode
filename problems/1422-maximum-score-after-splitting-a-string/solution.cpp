/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxScore(const string& s) {
    int ones = count(s.begin(), s.end(), '1');
    int zeros = 0;
    int answer = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == '0') {
        ++zeros;
      } else {
        --ones;
      }
      answer = max(answer, ones + zeros);
    }
    return answer;
  }
};
