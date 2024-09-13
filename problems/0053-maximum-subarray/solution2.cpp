/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-subarray/
 * Runtime: 41ms (99.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int minSum = 0;
    int answer = INT_MIN;
    for (int num : nums) {
      sum += num;
      answer = max(answer, sum - minSum);
      minSum = min(minSum, sum);
    }
    return answer;
  }
};
