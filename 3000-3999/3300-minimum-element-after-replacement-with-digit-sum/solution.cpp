/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minElement(vector<int>& nums) {
    int res = INT_MAX;
    for (int num : nums) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      res = min(res, sum);
    }
    return res;
  }
};
