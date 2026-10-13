/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
 * Runtime: 109ms (15.79%)
 */

class Solution {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    ranges::sort(nums, {}, [](int num) {
      return abs(num);
    });

    const int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n / 2; ++i) {
      sum -= nums[i] * nums[i];
    }
    for (int i = n / 2; i < n; ++i) {
      sum += nums[i] * nums[i];
    }
    return sum;
  }
};
