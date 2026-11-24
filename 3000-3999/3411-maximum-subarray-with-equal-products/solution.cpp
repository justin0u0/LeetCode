/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-subarray-with-equal-products/
 * Runtime: 1ms (72.03%)
 */

class Solution {
public:
  int maxLength(const vector<int>& nums) {
    int ans = 2;
    int left = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i - 1; j >= left; --j) {
        if (gcd(nums[i], nums[j]) != 1) {
          left = j + 1;
          break;
        }
      }
      ans = max(ans, i - left + 1);
    }
    return ans;
  }
};
