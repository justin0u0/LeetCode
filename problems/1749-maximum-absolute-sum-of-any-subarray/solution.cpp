/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int mx = 0;
    int mn = 0;
    int sum = 0;
    int result = 0;
    for (int num : nums) {
      sum += num;
      result = max(result, max(abs(sum - mx), abs(sum - mn)));
      mx = max(mx, sum);
      mn = min(mn, sum);
    }
    return result;
  }
};
