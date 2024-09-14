/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-average-subarray-i/
 * Runtime: 60ms (99.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }

    double answer = 1.0 * sum / k;
    for (int i = k; i < nums.size(); ++i) {
      sum += nums[i] - nums[i - k];
      answer = max(answer, 1.0 * sum / k);
    }
    return answer;
  }
};
