/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * Runtime: 69ms (98.65%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int suffix = accumulate(nums.begin(), nums.end(), 0);
    int prefix = 0;
    const int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      result[i] = (i + i - n) * nums[i] - prefix + suffix;
      prefix += nums[i];
      suffix -= nums[i];
    }
    return result;
  }
};

/*
result[0] = (nums[0] - nums[0]) + (nums[1] - nums[0]) + ... + (nums[n-1] - nums[0])
result[1] = (nums[1] - nums[0]) + (nums[1] - nums[1]) + ... + (nums[n-1] - nums[1])
result[2] = (nums[2] - nums[0]) + (nums[2] - nums[1]) + ... + (nums[n-1] - nums[2])

result[i] = i * nums[i] - (n-i) * (nums[i]) - nums[0...i] + nums[i:n]
*/
