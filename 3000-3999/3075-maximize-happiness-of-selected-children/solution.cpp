/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-happiness-of-selected-children/
 * Runtime: 97ms (99.65%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end(), greater<int>());
    long long answer = 0;
    for (int i = 0; i < k; ++i) {
      answer += max(happiness[i] - i, 0);
    }
    return answer;
  }
};
