/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Runtime: 29ms (98.66%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minSubArrayLen(int target, const vector<int>& nums) {
    int j = 0;
    int sum = 0;
    int answer = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum < target) {
        continue;
      }

      while (j <= i && sum >= target) {
        sum -= nums[j];
        ++j;
      }

      answer = min(answer, i - j + 2);
    }

    if (answer == INT_MAX) {
      return 0;
    }
    return answer;
  }
};
