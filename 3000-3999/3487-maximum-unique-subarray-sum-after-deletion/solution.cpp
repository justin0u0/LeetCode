/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxSum(const vector<int>& nums) {
    vector<bool> vis(101, false);
    int sum = 0;
    int mx = -100;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        if (!vis[nums[i]]) {
          vis[nums[i]] = true;
          sum += nums[i];
        }
      }
      mx = max(mx, nums[i]);
    }
    if (mx < 0) {
      return mx;
    }
    return sum;
  }
};
