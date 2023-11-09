/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-homogenous-substrings/
 * Runtime: 13ms (99.35%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int countHomogenous(const string& s) {
    int cnt = 1;
    int answer = 1;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      answer += cnt;
      if (answer >= mod) {
        answer -= mod;
      }
    }
    return answer;
  }
};
