/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
 * Runtime: 16ms (99.80%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  inline int solve(const string& s, char c, int k) {
    int answer = 0;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != c) {
        --k;
      }
      while (k < 0) {
        if (s[j] != c) {
          ++k;
        }
        ++j;
      }
      answer = max(answer, i - j + 1);
    }
    return answer;
  }
public:
  int maxConsecutiveAnswers(const string& answerKey, int k) {
    return max(solve(answerKey, 'T', k), solve(answerKey, 'F', k));
  }
};
