/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
 * Runtime: 7ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int getLastMoment(int n, const vector<int>& left, const vector<int>& right) {
    int answer = 0;
    for (const int l : left) {
      answer = max(answer, l);
    }
    for (const int r : right) {
      answer = max(answer, n - r);
    }
    return answer;
  }
};
