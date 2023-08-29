/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-penalty-for-a-shop/
 * Runtime: 15ms (99.36%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int bestClosingTime(const string& customers) {
    int answer = 0;
    int minPenalty = 0;
    int penalty = 0;
    for (int i = 0; i < customers.size(); ++i) {
      if (customers[i] == 'Y') {
        --penalty;
      } else {
        ++penalty;
      }
      if (minPenalty > penalty) {
        minPenalty = penalty;
        answer = i + 1;
      }
    }
    return answer;
  }
};
