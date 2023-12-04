/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-3-same-digit-number-in-string/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string largestGoodInteger(const string& num) {
    int cand = 0;
    for (int i = 1; i < num.size() - 1; ++i) {
      if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
        cand = max(cand, (int)num[i]);
      }
    }
    if (cand != 0) {
      return string(3, cand);
    }
    return "";
  }
};
