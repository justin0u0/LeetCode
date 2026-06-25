/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-with-majority-element-i/
 * Runtime: 29ms (83.66%)
 */

class Solution {
public:
  int countMajoritySubarrays(const vector<int>& nums, const int target) {
    const auto n = nums.size();

    vector<int> sum(n + 1, 0);
    int arrs = 0;

    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + (nums[i] == target);
      for (int j = 0; j <= i; ++j) {
        if (sum[i + 1] - sum[j] > (i - j + 1) / 2) {
          ++arrs;
        }
      }
    }

    return arrs;
  }
};
