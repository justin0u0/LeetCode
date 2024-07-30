/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
 * Runtime: 52ms (99.04%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumDeletions(const string& s) {
    int ra = 0;
    for (char c : s) {
      if (c == 'a') {
        ++ra;
      }
    }
    int rb = s.length() - ra;

    int answer = ra;
    int la = 0;
    int lb = 0;
    for (char c : s) {
      if (c == 'a') {
        --ra;
        ++la;
      } else {
        --rb;
        ++lb;
      }
      answer = min(answer, lb + ra);
    }
    return answer;
  }
};
