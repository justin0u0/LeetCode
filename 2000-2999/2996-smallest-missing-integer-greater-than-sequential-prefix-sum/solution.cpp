/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int missingInteger(const vector<int>& nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        sum += nums[i];
      } else {
        break;
      }
    }

    vector<bool> vis(51, false);
    for (int num : nums) {
      vis[num] = true;
    }
    while (sum <= 50 && vis[sum]) {
      ++sum;
    }
    return sum;
  }
};
