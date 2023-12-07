/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-odd-number-in-string/
 * Runtime: 19ms (98.43%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string largestOddNumber(const string& s) {
    string answer;
    answer.reserve(s.size());
    for (int i = s.size() - 1; i >= 0; --i) {
      if ((s[i] & 1) || !answer.empty()) {
        answer += s[i];
      }
    }
    while (!answer.empty() && answer.back() == '0') {
      answer.pop_back();
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
