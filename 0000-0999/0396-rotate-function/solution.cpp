/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rotate-function/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxRotateFunction(const vector<int>& nums) {
    const int n = nums.size();

    int f = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      f += i * nums[i];
      sum += nums[i];
    }

    int res = f;
    for (int i = n - 1; i > 0; --i) {
      f += sum - n * nums[i];
      res = max(res, f);
    }
    return res;
  }
};
