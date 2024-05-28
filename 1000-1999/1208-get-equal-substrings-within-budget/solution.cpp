/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/get-equal-substrings-within-budget/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int equalSubstring(const string& s, const string& t, int maxCost) {
    int j = 0;
    int cost = 0;
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
      cost += abs(s[i] - t[i]);
      while (j <= i && cost > maxCost) {
        cost -= abs(s[j] - t[j]);
        ++j;
      }
      answer = max(answer, i - j + 1);
    }
    return answer;
  }
};
